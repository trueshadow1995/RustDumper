#include "dumper.hpp"
#include "dumper_macros.hpp"
#include "util.hpp"

void dumper::write_game_assembly() {
  printf("[Rust Dumper] Writing GameAssembly headers...\n");

  PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)(game_base);
  PIMAGE_NT_HEADERS nt_headers =
      (PIMAGE_NT_HEADERS)(game_base + dos_header->e_lfanew);

  uint64_t gc_handles = 0;
  uint8_t* sig = nullptr;

  // Pattern 5 (now first): scan inside IL2CPP gchandle exports — most accurate.
  // Follows JMP stubs to reach the real implementation before scanning
  {
    const char* gc_exports[] = {
        "il2cpp_gchandle_get_target",
        "il2cpp_gchandle_new",
        "il2cpp_gchandle_new_weakref",
        "il2cpp_gchandle_free",
        nullptr
    };
    for (int e = 0; gc_exports[e] && !gc_handles; e++) {
      uint8_t* fn = (uint8_t*)GetProcAddress((HMODULE)game_base, gc_exports[e]);
      if (!fn) continue;

      // Follow JMP stubs up to 4 hops to reach the real implementation
      uint8_t* target = fn;
      for (int hop = 0; hop < 4; hop++) {
        if (target[0] == 0xE9) {
          // JMP rel32
          target = target + 5 + *(int32_t*)(target + 1);
        } else if (target[0] == 0xFF && target[1] == 0x25) {
          // JMP [RIP+X] — indirect through pointer
          uint8_t** ptr_addr = (uint8_t**)(target + 6 + *(int32_t*)(target + 2));
          if (is_valid_ptr(ptr_addr) && is_valid_ptr(*ptr_addr))
            target = *ptr_addr;
          else break;
        } else {
          break;
        }
      }

      write_to_log("[GC_HANDLES] Scanning %s -> impl at 0x%llx\n", gc_exports[e], (uint64_t)target);

      for (int i = 0; i < 0x400 && !gc_handles; i++) {
        // RIP-relative LEA or MOV: REX.W (48|4C) + (8D|8B) + ModRM RIP-rel
        if ((target[i] == 0x48 || target[i] == 0x4C) &&
            (target[i + 1] == 0x8D || target[i + 1] == 0x8B) &&
            (target[i + 2] & 0xC7) == 0x05) {
          // Check for AND reg, 7 within 40 bytes before or after
          int jlo = i > 40 ? i - 40 : 0;
          for (int j = jlo; j < i + 40 && j < 0x400 && !gc_handles; j++) {
            if (target[j] == 0x83 && (target[j + 1] & 0xF8) == 0xE0 && target[j + 2] == 0x07) {
              uint64_t candidate = DUMPER_RVA((uint64_t)dumper::relative_32(target + i, 3));
              if (candidate) {
                gc_handles = candidate;
                write_to_log("[GC_HANDLES] Pattern 5 (export %s impl) - RVA: 0x%llx\n",
                             gc_exports[e], gc_handles);
              }
            }
          }
        }
      }
    }
  }

  // Pattern 1: LEA RAX, [rip+?] then AND ECX, 7 then shift 3
  if (!gc_handles) {
    sig = FIND_PATTERN_IMAGE(
        game_base, "\x48\x8D\x05\xCC\xCC\xCC\xCC\x83\xE1\x07\xC1\xCC\x03");
    if (sig) {
      gc_handles = DUMPER_RVA((uint64_t)dumper::relative_32(sig, 3));
      write_to_log("[GC_HANDLES] Pattern 1 (LEA RAX + AND ECX,7) - RVA: 0x%llx\n",
                   gc_handles);
    }
  }

  // Pattern 2: LEA RCX, [rip+?] then AND ECX, 7
  if (!gc_handles) {
    sig = FIND_PATTERN_IMAGE(game_base,
                             "\x48\x8D\x0D\xCC\xCC\xCC\xCC\x83\xE1\x07");
    if (sig) {
      gc_handles = DUMPER_RVA((uint64_t)dumper::relative_32(sig, 3));
      write_to_log(
          "[GC_HANDLES] Pattern 2 (LEA RCX + AND ECX,7) - RVA: 0x%llx\n",
          gc_handles);
    }
  }

  // Pattern 3: LEA RDX, [rip+?] then AND any reg, 7
  if (!gc_handles) {
    sig = FIND_PATTERN_IMAGE(game_base,
                             "\x48\x8D\x15\xCC\xCC\xCC\xCC\x83\xCC\x07");
    if (sig) {
      gc_handles = DUMPER_RVA((uint64_t)dumper::relative_32(sig, 3));
      write_to_log(
          "[GC_HANDLES] Pattern 3 (LEA RDX + AND reg,7) - RVA: 0x%llx\n",
          gc_handles);
    }
  }

  // Pattern 4: LEA RBX, [rip+?] then AND any reg, 7
  if (!gc_handles) {
    sig = FIND_PATTERN_IMAGE(game_base,
                             "\x48\x8D\x1D\xCC\xCC\xCC\xCC\x83\xCC\x07");
    if (sig) {
      gc_handles = DUMPER_RVA((uint64_t)dumper::relative_32(sig, 3));
      write_to_log(
          "[GC_HANDLES] Pattern 4 (LEA RBX + AND reg,7) - RVA: 0x%llx\n",
          gc_handles);
    }
  }

  if (!gc_handles) {
    write_to_log("[GC_HANDLES] All patterns failed - gc_handles will be 0\n");
  }

  dumper::write_to_file("namespace GameAssembly {\n");
  dumper::write_to_file("\tconstexpr const static size_t timestamp = 0x%x;\n",
                        nt_headers->FileHeader.TimeDateStamp);
  dumper::write_to_file("\tconstexpr const static size_t gc_handles = 0x%x;\n",
                        gc_handles);
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_resolve_icall = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_resolve_icall" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_array_new = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_array_new" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_assembly_get_image = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_assembly_get_image" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_class_from_name = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_class_from_name" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_class_get_method_from_name = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_class_get_method_from_name" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_class_get_type = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_class_get_type" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_domain_get = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_domain_get" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_domain_get_assemblies = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_domain_get_assemblies" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_gchandle_get_target = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_gchandle_get_target" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_gchandle_new = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_gchandle_new" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_gchandle_free = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_gchandle_free" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_method_get_name = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_method_get_name" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_object_new = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_object_new" ) ) );
        dumper::write_to_file( "\tconstexpr const static size_t il2cpp_type_get_object = 0x%x;\n", GA_EXPORT_RVA( "il2cpp_type_get_object" ) ) );
        dumper::write_to_file("}\n\n");
}
