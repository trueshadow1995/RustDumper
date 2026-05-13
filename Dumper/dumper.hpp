#pragma once

#include "il2cpp_lib.hpp"
#include "unity_lib.hpp"
#include "rust_lib.hpp"
#include "hook_lib.hpp"
#include <windows.h>
#include <excpt.h>

namespace dumper
{
	void produce();
	void produce_unity();
	void write_game_assembly();

	void dump_call( uint64_t function, uint32_t limit, uint32_t depth = 0 );

	extern FILE* outfile_handle;
	extern FILE* outfile_log_handle;
	extern uint64_t game_base;
	extern uint64_t unity_base;

	extern int get_class_type_definition_index( il2cpp::il2cpp_class_t* klass );

	char* clean_klass_name( const char* klass_name );
	char* clean_inner_klass_name( il2cpp::il2cpp_class_t* klass );
	void write_to_file( const char* format, ... );
	void write_to_log( const char* format, ... );
	void flush();

	extern uint64_t start_write_value;

	// Cached field offsets populated by produce() for use by recorder.cpp
	extern uint64_t g_clActiveItem_offset;

	void dump_protobuf_methods( il2cpp::il2cpp_class_t* klass );

	void dump_projectile_shoot( il2cpp::il2cpp_object_t* object );
	void dump_player_projectile_update( il2cpp::il2cpp_object_t* object );
	void dump_player_projectile_attack( il2cpp::il2cpp_object_t* object );

	long exception_handler( EXCEPTION_POINTERS* exception_info );
}

#include "pe_utils.hpp"