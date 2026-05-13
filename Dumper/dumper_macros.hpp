#pragma once
#include "il2cpp_lib.hpp"

// Forward declarations for internal helpers used by macros and produce bodies
const char *format_string(const char *fmt, ...);
const char *format_method(il2cpp::method_info_t *method);
il2cpp::il2cpp_class_t *get_outer_class(il2cpp::il2cpp_class_t *klass);
il2cpp::il2cpp_class_t *get_inner_static_class(il2cpp::il2cpp_class_t *klass);
void dump_fn_to_file(const char *label, uint8_t *address);

// ---- Search helpers ----

#define SEARCH_FOR_CLASS_BY_FIELD_COUNT(field_ct, equality, ...)               \
  [=]() -> il2cpp::il2cpp_class_t * {                                          \
    il2cpp::il2cpp_class_t *match_klasses[] = {__VA_ARGS__};                   \
    return il2cpp::search_for_class_by_field_count(                            \
        match_klasses, _countof(match_klasses), field_ct, equality);           \
  }()

#define SEARCH_FOR_STATIC_CLASS_BY_METHOD_COUNT(method_ct, ret_type,           \
                                                wanted_vis, wanted_flags, ...) \
  [=]() -> il2cpp::il2cpp_class_t * {                                          \
    il2cpp::il2cpp_type_t *param_types[] = {__VA_ARGS__};                      \
    return il2cpp::                                                            \
        search_for_static_class_with_method_with_rettype_param_types(          \
            method_ct, ret_type, wanted_vis, wanted_flags, param_types,        \
            _countof(param_types));                                            \
  }()

#define SEARCH_MEMBER_BY_FIELD_TYPE_CLASS_CONTAINS_MULTIPLE(...)               \
  [=]() -> il2cpp::field_info_t * {                                            \
    const char *search_terms[] = {__VA_ARGS__};                                \
    return il2cpp::get_field_if_type_contains_terms(                           \
        dumper_klass, search_terms, _countof(search_terms));                   \
  }()

#define SEARCH_FOR_METHOD_WITH_RETTYPE_PARAM_TYPES(                            \
    filter, ret_type, wanted_vis, wanted_flags, ...)                           \
  [=]() -> il2cpp::method_info_t * {                                           \
    il2cpp::il2cpp_type_t *param_types[] = {__VA_ARGS__};                      \
    return il2cpp::get_method_by_return_type_and_param_types(                  \
        filter, dumper_klass, ret_type, wanted_vis, wanted_flags, param_types, \
        _countof(param_types));                                                \
  }()

#define SEARCH_FOR_METHOD_WITH_RETTYPE_PARAM_TYPES_STR(                        \
    filter, ret_type, wanted_vis, wanted_flags, ...)                           \
  [=]() -> il2cpp::method_info_t * {                                           \
    const char *params[] = {__VA_ARGS__};                                      \
    return il2cpp::get_method_by_return_type_and_param_types_str(              \
        filter, dumper_klass, ret_type, wanted_vis, wanted_flags, params,      \
        _countof(params));                                                     \
  }()

#define SEARCH_FOR_METHOD_WITH_RETTYPE_PARAM_TYPES_SIZE(                       \
    filter, idx, ret_type, wanted_vis, wanted_flags, ...)                      \
  [=]() -> il2cpp::method_info_t * {                                           \
    il2cpp::il2cpp_type_t *param_types[] = {__VA_ARGS__};                      \
    return il2cpp::get_method_by_return_type_and_param_types_size(             \
        filter, idx, dumper_klass, ret_type, wanted_vis, wanted_flags,         \
        param_types, _countof(param_types), nullptr, false);                   \
  }()

#define SEARCH_FOR_METHOD_IN_METHOD_WITH_RETTYPE(                              \
    klass, filter, ret_type, wanted_vis, wanted_flags, param_ct)               \
  il2cpp::get_method_in_method_by_return_type(                                 \
      klass, filter, ret_type, wanted_vis, wanted_flags, param_ct);

#define SEARCH_FOR_METHOD_IN_METHOD_WITH_RETTYPE_PARAM_TYPES(                  \
    klass, filter, ret_type, wanted_vis, wanted_flags, ...)                    \
  [=]() -> il2cpp::method_info_t * {                                           \
    il2cpp::il2cpp_type_t *param_types[] = {__VA_ARGS__};                      \
    return il2cpp::get_method_in_method_by_return_type_and_param_types(        \
        klass, filter, ret_type, wanted_vis, wanted_flags, param_types,        \
        _countof(param_types));                                                \
  }()

#define SEARCH_FOR_VIRTUAL_METHOD_WITH_RETTYPE_PARAM_TYPES(                    \
    filter, ret_type, wanted_vis, wanted_flags, ...)                           \
  [=]() -> il2cpp::virtual_method_t {                                          \
    il2cpp::il2cpp_type_t *param_types[] = {__VA_ARGS__};                      \
    return il2cpp::get_virtual_method_by_return_type_and_param_types(          \
        filter, dumper_klass, ret_type, wanted_vis, wanted_flags, param_types, \
        _countof(param_types));                                                \
  }()

#define SEARCH_FOR_VIRTUAL_METHOD_WITH_RETTYPE(filter, ret_type, wanted_vis,   \
                                               wanted_flags)                   \
  il2cpp::get_virtual_method_by_return_type_and_param_types(                   \
      filter, dumper_klass, ret_type, wanted_vis, wanted_flags, nullptr, 0);

// ---- Core dumper aliases ----

#define DUMPER_VIS_DONT_CARE 0
#define DUMPER_ATTR_DONT_CARE 0

#define DUMPER_RVA(X) X == 0 ? 0 : X - dumper::game_base
#define DUMPER_RVA_UNITY(X) X - dumper::unity_base
#define DUMPER_CLASS(name) il2cpp::get_class_by_name(name)
#define DUMPER_CLASS_NAMESPACE(namespaze, name)                                \
  il2cpp::get_class_by_name(name, namespaze)
#define DUMPER_METHOD(klass, name)                                             \
  il2cpp::get_method_by_name(klass, name)->get_fn_ptr<uint64_t>()

#define DUMPER_TYPE(name) DUMPER_CLASS(name)->type()
#define DUMPER_TYPE_NAMESPACE(namespaze, name)                                 \
  DUMPER_CLASS_NAMESPACE(namespaze, name)->type()

#define DUMPER_PTR_CLASS_NAME(dump_name, klass_ptr)                            \
  dumper::write_to_file("#define " dump_name "_ClassName \"%s\"\n",            \
                        clean_inner_klass_name(klass_ptr));                    \
  dumper::write_to_file("#define " dump_name "_ClassNameShort \"%s\"\n",       \
                        klass_ptr->name());

#define DUMPER_SECTION(dump_name)                                              \
  dumper::write_to_file("\t\n// " dump_name "\n");

#define DUMPER_CLASS_HEADER(klass_name)                                        \
  char *name = dumper::clean_klass_name(klass_name);                           \
  dumper::write_to_file(                                                       \
      "#define %s_TypeDefinitionIndex %d\n\n", name,                           \
      dumper::get_class_type_definition_index(dumper_klass));                  \
  dumper::write_to_file("namespace %s_Offsets {\n", name);                     \
  if (dumper_klass && dumper::game_base) {                                     \
    uint64_t _slot =                                                           \
        dumper::find_value_in_data_section((uint64_t)dumper_klass);            \
    if (_slot && _slot > dumper::game_base) {                                  \
      dumper::write_to_file(                                                   \
          "\tinline constexpr std::uintptr_t typeinfo = 0x%llx;\n",            \
          _slot - dumper::game_base);                                          \
    }                                                                          \
  }

#define DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE(klass_name, namespaze)          \
  {                                                                            \
    il2cpp::il2cpp_class_t *dumper_klass =                                     \
        il2cpp::get_class_by_name(klass_name, namespaze);                      \
    DUMPER_CLASS_HEADER(klass_name);

#define DUMPER_CLASS_BEGIN_FROM_NAME(klass_name)                               \
  DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE(klass_name, "")

#define DUMPER_CLASS_BEGIN_FROM_PTR(dump_name, klass_ptr)                      \
  {                                                                            \
    il2cpp::il2cpp_class_t *dumper_klass = klass_ptr;                          \
    dumper::write_to_file("// obf name: %s::%s\n", dumper_klass->namespaze(),  \
                          dumper_klass->name());                               \
    DUMPER_PTR_CLASS_NAME(dump_name, klass_ptr);                               \
    DUMPER_CLASS_HEADER(dump_name);

#define DUMPER_CLASS_END                                                       \
  dumper::write_to_file("}\n\n");                                              \
  dumper::flush();                                                             \
  }

#define DUMP_CLASS_NAME(dump_name, klass_ptr)                                  \
  dumper::write_to_file("// obf name: %s::%s\n", klass_ptr->namespaze(),       \
                        klass_ptr->name());                                    \
  DUMPER_PTR_CLASS_NAME(dump_name, klass_ptr);

// ---- Member dump helpers ----

#define DUMP_MEMBER_BY_X(NAME, X)                                              \
  uint64_t NAME##_Offset = X;                                                  \
  dumper::write_to_file("\tconstexpr const static size_t " #NAME " = 0x%x;\n", \
                        static_cast<uint32_t>(NAME##_Offset))

#define DUMP_MEMBER_BY_FIELD_TYPE_NAME_ATTRS(NAME, field_type, wanted_vis,     \
                                             wanted_attrs)                     \
  DUMP_MEMBER_BY_X(                                                            \
      NAME, il2cpp::get_field_by_type_name_attrs(dumper_klass, field_type,     \
                                                 wanted_vis, wanted_attrs)     \
                ->offset(dumper_klass))
#define DUMP_MEMBER_BY_FIELD_TYPE_CLASS_CONTAINS(NAME, search)                 \
  DUMP_MEMBER_BY_X(NAME,                                                       \
                   il2cpp::get_field_if_type_contains(dumper_klass, search)    \
                       ->offset(dumper_klass))
#define DUMP_MEMBER_BY_FIELD_TYPE_CLASS_CONTAINS_ATTRS(                        \
    NAME, search, wanted_vis, wanted_attrs)                                    \
  DUMP_MEMBER_BY_X(NAME, il2cpp::get_field_if_type_contains(                   \
                             dumper_klass, search, wanted_vis, wanted_attrs)   \
                             ->offset(dumper_klass))
#define DUMP_MEMBER_BY_FIELD_TYPE_CLASS(NAME, wanted_klass)                    \
  DUMP_MEMBER_BY_X(NAME, il2cpp::get_field_from_field_type_class(dumper_klass, \
                                                                 wanted_klass) \
                             ->offset(dumper_klass))
#define DUMP_MEMBER_BY_NAME(NAME)                                              \
  DUMP_MEMBER_BY_X(                                                            \
      NAME,                                                                    \
      il2cpp::get_field_by_name(dumper_klass, #NAME)->offset(dumper_klass))
#define DUMP_MEMBER_BY_NEAR_OFFSET(NAME, off)                                  \
  DUMP_MEMBER_BY_X(                                                            \
      NAME,                                                                    \
      il2cpp::get_field_by_offset(dumper_klass, off)->offset(dumper_klass))
#define DUMP_MEMBER_BY_FIELD_TYPE_CLASS_CONTAINS_MULTIPLE(NAME, ...)           \
  DUMP_MEMBER_BY_X(                                                            \
      NAME, SEARCH_MEMBER_BY_FIELD_TYPE_CLASS_CONTAINS_MULTIPLE(__VA_ARGS__)   \
                ->offset(dumper_klass))
#define DUMP_MEMBER_BY_TYPE_METHOD_ATTRIBUTE(                                  \
    NAME, type_klass, method_attr, wanted_vis, wanted_attrs, want_or_ignore)   \
  DUMP_MEMBER_BY_X(NAME, il2cpp::get_field_by_type_attrs_method_attr(          \
                             dumper_klass, type_klass, method_attr,            \
                             wanted_attrs, wanted_vis, want_or_ignore)         \
                             ->offset(dumper_klass))

#define DUMP_ALL_MEMBERS_OF_TYPE(NAME, wanted_type, wanted_vis, wanted_attrs)  \
  [=]() {                                                                      \
    void *iter = nullptr;                                                      \
    int i = 0;                                                                 \
    while (il2cpp::field_info_t *field = dumper_klass->fields(&iter)) {        \
      if (strcmp(field->type()->name(), wanted_type->name()) == 0) {           \
        int attrs = field->type()->attributes();                               \
        int vis = attrs & TYPE_ATTRIBUTE_VISIBILITY_MASK;                      \
        if ((wanted_vis && (vis != wanted_vis)) ||                             \
            (wanted_attrs && !(wanted_attrs & attrs)))                         \
          continue;                                                            \
        dumper::write_to_file(                                                 \
            "\tconstexpr const static size_t %s_%d = 0x%x;\n", NAME, i,        \
            field->offset(dumper_klass));                                      \
        i++;                                                                   \
      }                                                                        \
    }                                                                          \
  }()

// ---- Method dump helpers ----

#define DUMP_METHOD_BY_RETURN_TYPE_STR(NAME, filter, ret_type, param_ct)       \
  DUMP_MEMBER_BY_X(NAME,                                                       \
                   DUMPER_RVA(il2cpp::get_method_by_return_type_str(           \
                                  filter, dumper_klass, ret_type, param_ct)    \
                                  ->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_RETURN_TYPE_ATTRS(NAME, filter, ret_type, param_ct,     \
                                         wanted_vis, wanted_attrs)             \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(il2cpp::get_method_by_return_type_attrs(   \
                                        filter, dumper_klass, ret_type,        \
                                        wanted_attrs, wanted_vis, param_ct)    \
                                        ->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_RETURN_TYPE_SIZE(NAME, filter, ret_type, wanted_vis,    \
                                        wanted_attrs, idx)                     \
  DUMP_MEMBER_BY_X(                                                            \
      NAME, DUMPER_RVA(il2cpp::get_method_by_return_type_and_param_types_size( \
                           filter, idx, dumper_klass, ret_type, wanted_attrs,  \
                           wanted_vis, nullptr, 0, nullptr, false)             \
                           ->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_SIG_REL(NAME, base, sig, off)                           \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(uint64_t(dumper::relative_32(              \
                             FIND_PATTERN(base, 0x1000, sig), off))))
#define DUMP_METHOD_BY_INFO_PTR(NAME, ptr)                                     \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(ptr->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_PARAM_CLASS(NAME, filter, param_class, param_ct,        \
                                   wanted_vis, wanted_flags)                   \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(il2cpp::get_method_by_param_class(         \
                                        filter, dumper_klass, param_class,     \
                                        param_ct, wanted_vis, wanted_flags)    \
                                        ->get_fn_ptr<uint64_t>()))

#define DUMP_METHOD_BY_RETURN_TYPE_METHOD_ATTRIBUTE(                           \
    NAME, filter, ret_type, method_attr, param_ct, wanted_vis, wanted_attrs,   \
    want_or_ignore)                                                            \
  DUMP_MEMBER_BY_X(                                                            \
      NAME, DUMPER_RVA(il2cpp::get_method_by_return_type_attrs_method_attr(    \
                           filter, dumper_klass, ret_type, method_attr,        \
                           wanted_attrs, wanted_vis, param_ct, want_or_ignore) \
                           ->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_RETURN_TYPE_METHOD_ATTRIBUTE_SIZE(                      \
    NAME, filter, ret_type, method_attr, wanted_vis, wanted_attrs,             \
    want_or_ignore, idx)                                                       \
  DUMP_MEMBER_BY_X(                                                            \
      NAME,                                                                    \
      DUMPER_RVA(il2cpp::get_method_by_return_type_and_param_types_size(       \
                     filter, idx, dumper_klass, ret_type, wanted_vis,          \
                     wanted_attrs, nullptr, 0, method_attr, want_or_ignore)    \
                     ->get_fn_ptr<uint64_t>()))

#define DUMP_METHOD_BY_NAME(NAME)                                              \
  DUMP_MEMBER_BY_X(NAME,                                                       \
                   DUMPER_RVA(il2cpp::get_method_by_name(dumper_klass, #NAME)  \
                                  ->get_fn_ptr<uint64_t>()));
#define DUMP_METHOD_BY_NAME_STR(NAME, method_name)                             \
  DUMP_MEMBER_BY_X(                                                            \
      NAME, DUMPER_RVA(il2cpp::get_method_by_name(dumper_klass, method_name)   \
                           ->get_fn_ptr<uint64_t>()));
#define DUMP_METHOD_BY_NAME_STR_ARG_CT(NAME, method_name, arg_count)           \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(il2cpp::get_method_by_name(                \
                                        dumper_klass, method_name, arg_count)  \
                                        ->get_fn_ptr<uint64_t>()));
#define DUMP_METHOD_BY_PARAM_NAME(NAME, method_name, param_name, param_idx)    \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA(il2cpp::get_method_by_param_name(          \
                                        NO_FILT, dumper_klass, method_name,    \
                                        param_name, param_idx)                 \
                                        ->get_fn_ptr<uint64_t>()))
#define DUMP_METHOD_BY_ICALL(NAME, ICALL)                                      \
  DUMP_MEMBER_BY_X(NAME, DUMPER_RVA_UNITY(il2cpp::resolve_icall(ICALL)));

#define DUMP_VIRTUAL_METHOD(NAME, virtual_method)                              \
  DUMP_MEMBER_BY_X(NAME,                                                       \
                   DUMPER_RVA(virtual_method.method->get_fn_ptr<uint64_t>())); \
  dumper::write_to_file(                                                       \
      "\tconstexpr const static size_t %s_vtableoff = 0x%x;\n", #NAME,         \
      virtual_method.offset)

// ---- Misc ----

#define DUMP_ENCRYPTED_MEMBER(NAME, FIELD)                                     \
  {                                                                            \
    il2cpp::il2cpp_type_t *type = FIELD->type();                               \
    il2cpp::il2cpp_class_t *klass = type->klass();                             \
    il2cpp::method_info_t *to_string =                                         \
        il2cpp::get_method_by_name(klass, "ToString");                         \
    dumper::write_to_file("// type name: %s\n", type->name());                 \
    dumper::write_to_file("\tconstexpr const static size_t " #NAME             \
                          " = 0x%x;\n",                                        \
                          FIELD->offset());                                    \
    dumper::write_to_file("\tconstexpr const static size_t " #NAME             \
                          "_ToString = 0x%x;\n",                               \
                          DUMPER_RVA(to_string->get_fn_ptr<uint64_t>()));      \
  }

#define DUMPER_OFFSET(NAME) NAME##_Offset

#define VALUE_CLASS 0
#define VALUE_METHOD 1

#define CHECK_RESOLVED_VALUE(value_type, dump_name, value)                     \
  if (!value) {                                                                \
    dumper::write_to_log("[ERROR] Failed to resolve %s\n", dump_name);         \
    fclose(dumper::outfile_handle);                                            \
    fclose(dumper::outfile_log_handle);                                        \
    return;                                                                    \
  } else {                                                                     \
    if (value_type == VALUE_CLASS) {                                           \
      dumper::write_to_log("[SUCCESS] %s: %s\n", dump_name,                    \
                           ((il2cpp::il2cpp_class_t *)value)->type()->name()); \
    } else if (value_type == VALUE_METHOD) {                                   \
      const char *method_fmt = format_method((il2cpp::method_info_t *)value);  \
      dumper::write_to_log("[SUCCESS] %s: %s", dump_name, method_fmt);         \
    }                                                                          \
  }

#define CHECK_RESOLVED_VALUE_SOFT(value_type, dump_name, value)                \
  if (!value) {                                                                \
    dumper::write_to_log("[WARNING] Failed to resolve %s - continuing\n",      \
                         dump_name);                                           \
  } else {                                                                     \
    if (value_type == VALUE_CLASS) {                                           \
      dumper::write_to_log("[SUCCESS] %s: %s\n", dump_name,                    \
                           ((il2cpp::il2cpp_class_t *)value)->type()->name()); \
    } else if (value_type == VALUE_METHOD) {                                   \
      const char *method_fmt = format_method((il2cpp::method_info_t *)value);  \
      dumper::write_to_log("[SUCCESS] %s: %s", dump_name, method_fmt);         \
    }                                                                          \
  }

#define GA_EXPORT_RVA(x) DUMPER_RVA( ( uint64_t )GetProcAddress( ( HMODULE )dumper::game_base, x )
