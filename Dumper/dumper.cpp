#include "dumper.hpp"
#include "dumper_macros.hpp"
#include <stdlib.h>
#include "util.hpp"

const char* format_string(const char* fmt, ...) {
  static char buffer[256];
  va_list val;
  va_start(val, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, val);
  va_end(val);
  return buffer;
}

il2cpp::il2cpp_class_t* get_outer_class(il2cpp::il2cpp_class_t* klass) {
  if (!klass) return nullptr;

  if (!klass->type()) return nullptr;

  const char* begin = klass->type()->name();
  const char* end = strchr(begin, '.');
  size_t length = end - begin;

  char buffer[128]{};
  memcpy(buffer, begin, length);
  buffer[length] = '\0';

  return il2cpp::get_class_by_name(buffer, klass->namespaze());
}

il2cpp::il2cpp_class_t* get_inner_static_class(il2cpp::il2cpp_class_t* klass) {
  if (!klass) return nullptr;

  if (!klass->type()) return nullptr;

  void* iter = nullptr;
  while (il2cpp::il2cpp_class_t* _klass = klass->nested_types(&iter)) {
    if (_klass->method_count() != 1) continue;

    if (!il2cpp::get_method_by_name(_klass, ".cctor")) continue;

    iter = nullptr;
    while (il2cpp::field_info_t* field = _klass->fields(&iter))
      if (!(field->flags() & FIELD_ATTRIBUTE_STATIC)) continue;

    return _klass;
  }

  return nullptr;
}

void dump_fn_to_file(const char* label, uint8_t* address) {
  dumper::write_to_file("\tconst static uint8_t %s[] = { ", label);

  size_t len = util::get_function_attributes(address, 16384).length;

  for (uint32_t i = 0; i < len - 1; i++) {
    dumper::write_to_file("0x%02X, ", address[i]);
  }

  dumper::write_to_file("0x%02X };\n", address[len - 1]);
}

FILE* dumper::outfile_handle = nullptr;
FILE* dumper::outfile_log_handle = nullptr;
uint64_t dumper::game_base = 0;
uint64_t dumper::unity_base = 0;
uint64_t dumper::start_write_value = 0;
uint64_t dumper::g_clActiveItem_offset = 0;

void dumper::write_to_file(const char* format, ...) {
  char buffer[1024] = {0};
  memset(buffer, 0, sizeof(buffer));

  va_list args;
  va_start(args, format);
  vsprintf_s(buffer, format, args);
  va_end(args);

  fwrite(buffer, strlen(buffer), 1, outfile_handle);
}

void dumper::write_to_log(const char* format, ...) {
  char buffer[1024] = {0};
  memset(buffer, 0, sizeof(buffer));

  va_list args;
  va_start(args, format);
  vsprintf_s(buffer, format, args);
  va_end(args);

  fwrite(buffer, strlen(buffer), 1, outfile_log_handle);
  fflush(outfile_log_handle);
}

const char* format_method(il2cpp::method_info_t* method) {
  static char buffer[1024]{};
  memset(buffer, 0, sizeof(buffer));

  uint32_t param_ct = method->param_count();

  snprintf(buffer, sizeof(buffer), "%s.%s(", method->klass()->type()->name(),
           method->name());

  for (uint32_t j = 0; j < param_ct; ++j) {
    snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer),
             "%s %s%s", method->get_param(j)->klass()->type()->name(),
             method->get_param_name(j), (j == param_ct - 1) ? "" : ", ");
  }

  snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), ");\n");
  return buffer;
}

void dumper::flush() { fflush(outfile_handle); }

char* dumper::clean_klass_name(const char* klass_name) {
  static char buffer[1024] = {0};
  memset(buffer, 0, sizeof(buffer));

  strcpy(buffer, klass_name);

  char junk_chars[] = {'/', '-', '.', '<', '>', '%'};
  for (int i = 0; i < _countof(junk_chars); i++)
    while (char* found = strchr(buffer, junk_chars[i])) *found = '_';

  return buffer;
}

char* dumper::clean_inner_klass_name(il2cpp::il2cpp_class_t* klass) {
  static char buffer[1024] = {0};
  memset(buffer, 0, sizeof(buffer));

  il2cpp::il2cpp_type_t* type = klass->type();
  if (!type) return nullptr;

  strcpy(buffer, type->name());

  if (!strchr(buffer, '.')) return buffer;

  *strchr(buffer, '.') = '/';

  return buffer;
}

void dumper::dump_call(uint64_t function, uint32_t limit, uint32_t depth) {
  if (limit == 0) return;

  il2cpp::call_set_t* calls = il2cpp::get_inverse_calls(function);

  if (calls) {
    uint32_t idx = 0;

    for (auto call : *calls) {
      for (uint32_t i = 0; i < depth; i++) write_to_file("\t");

      if (il2cpp::method_info_t* method =
              il2cpp::method_info_t::from_addr(call)) {
        const char* method_name_fmt = format_method(method);
        write_to_file("%s", method_name_fmt);
      }

      else
        write_to_file("%02i %p\n", idx++, call - game_base);

      dump_call(call, limit - 1, depth + 1);
    }
  }
}

int dumper::get_class_type_definition_index(il2cpp::il2cpp_class_t* klass) {
  if (!klass) return -1;
  const uint8_t* p = reinterpret_cast<const uint8_t*>(klass);
  for (int off = 0x100; off <= 0x140; off += 4) {
    uint32_t v = *reinterpret_cast<const uint32_t*>(p + off);
    if ((v >> 24) == 0x02 && (v & 0x00FFFFFF) != 0)
      return static_cast<int>((v & 0x00FFFFFF) - 1);
  }
  return -1;
}
