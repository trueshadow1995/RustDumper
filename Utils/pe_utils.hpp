#pragma once

#include <windows.h>
#include <stdint.h>

namespace dumper {

	struct image_section_info_t {
		image_section_info_t( uint64_t _address, uint32_t _size ) :
			address( _address ), size( _size ) {};

		uint64_t address;
		uint32_t size;
	};

	__forceinline uint32_t get_image_size( uint8_t* image ) {
		PIMAGE_DOS_HEADER dos_header = ( PIMAGE_DOS_HEADER ) ( image );
		PIMAGE_NT_HEADERS nt_headers = ( PIMAGE_NT_HEADERS ) ( image + dos_header->e_lfanew );
		return nt_headers->OptionalHeader.SizeOfImage;
	}

	__forceinline uint8_t* relative_32( uint8_t* inst, uint32_t offset ) {
		int32_t rel_offset = *( int32_t* ) ( inst + offset );
		return ( inst + rel_offset + offset + sizeof( int32_t ) );
	}

	__forceinline bool compare_pattern( uint8_t* base, uint8_t* pattern, size_t mask ) {
		for ( ; mask; ++base, ++pattern, mask-- ) {
			if ( *pattern != 0xCC && *base != *pattern ) {
				return false;
			}
		}
		return true;
	}

	__forceinline uint8_t* find_pattern( uint8_t* base, size_t size, uint8_t* pattern, size_t mask ) {
		size -= mask;
		for ( SIZE_T i = 0; i <= size; ++i ) {
			uint8_t* addr = &base[ i ];
			if ( compare_pattern( addr, pattern, mask ) )
				return addr;
		}
		return nullptr;
	}

	__forceinline uint8_t* find_pattern_image( uint8_t* image, uint8_t* pattern, size_t mask ) {
		PIMAGE_DOS_HEADER dosHeader = ( PIMAGE_DOS_HEADER ) ( image );
		PIMAGE_NT_HEADERS ntHeaders = ( PIMAGE_NT_HEADERS ) ( image + dosHeader->e_lfanew );

		uint8_t* sectionBase = ( uint8_t* ) &ntHeaders->OptionalHeader + ntHeaders->FileHeader.SizeOfOptionalHeader;

		for ( uint32_t i = 0; i < ntHeaders->FileHeader.NumberOfSections; i++ ) {
			PIMAGE_SECTION_HEADER section =
				( PIMAGE_SECTION_HEADER ) ( sectionBase + ( i * sizeof( IMAGE_SECTION_HEADER ) ) );

			if ( ( section->Characteristics & IMAGE_SCN_MEM_EXECUTE ) == 0 ||
				( section->Characteristics & IMAGE_SCN_MEM_DISCARDABLE ) != 0 )
				continue;

			uint32_t len = max( section->SizeOfRawData, section->Misc.VirtualSize );
			uint8_t* result = find_pattern( image + section->VirtualAddress, len, pattern, mask );
			if ( result )
				return result;
		}
		return nullptr;
	}

	__forceinline image_section_info_t get_section_info( uint8_t* image, const char* name ) {
		PIMAGE_DOS_HEADER dosHeader = ( PIMAGE_DOS_HEADER )( image );
		PIMAGE_NT_HEADERS ntHeaders = ( PIMAGE_NT_HEADERS )( image + dosHeader->e_lfanew );

		uint8_t* sectionBase = ( uint8_t* )&ntHeaders->OptionalHeader + ntHeaders->FileHeader.SizeOfOptionalHeader;

		for ( uint32_t i = 0; i < ntHeaders->FileHeader.NumberOfSections; i++ ) {
			PIMAGE_SECTION_HEADER section =
				( PIMAGE_SECTION_HEADER )( sectionBase + ( i * sizeof( IMAGE_SECTION_HEADER ) ) );

			char* section_name = ( char* )section->Name;
			if ( !strcmp( section_name, name ) ) {
				uint64_t address = ( uint64_t )image + section->VirtualAddress;
				uint32_t size = section->Misc.VirtualSize;
				return image_section_info_t( address, size );
			}
		}
		return image_section_info_t( 0, 0 );
	}

	template <typename T>
	__forceinline uint64_t find_value_in_data_section( T value ) {
		image_section_info_t data_section = get_section_info( ( uint8_t* )game_base, ".data" );
		if ( !data_section.address || !data_section.size )
			return 0;

		uint64_t current_address = data_section.address;
		uint64_t end_address = data_section.address + data_section.size;

		while ( current_address < end_address ) {
			uint64_t _value = *( uint64_t* )( current_address );
			if ( _value == ( uint64_t )value )
				return current_address;
			current_address += 8;
		}
		return 0;
	}
}

#define FIND_PATTERN( base, size, sig ) dumper::find_pattern( ( uint8_t* ) base, size, ( uint8_t* ) sig, sizeof( sig ) - 1 )
#define FIND_PATTERN_IMAGE( base, sig ) dumper::find_pattern_image( ( uint8_t* ) base, ( uint8_t* ) sig, sizeof( sig ) - 1 )
