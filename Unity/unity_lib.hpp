#pragma once

#define _this (uint64_t)this

namespace system_c {
class string_t {
  char zpad[0x10];

public:
  int size;
  wchar_t str[256 + 1];
  string_t() {};
  string_t(const wchar_t *st) {
    size = min((int)wcslen((wchar_t *)st), 256);
    for (int i = 0; i < size; i++) {
      str[i] = st[i];
    }
    str[size] = 0;
  }

  static string_t *create_string(const wchar_t *str) {
    static string_t *(*fast_allocate_string_f)(uint32_t) =
        (decltype(fast_allocate_string_f))il2cpp::get_method_by_name(
            il2cpp::get_class_by_name("String", "System"), "FastAllocateString")
            ->get_fn_ptr<void *>();

    int length = wcslen(str);
    string_t *string = fast_allocate_string_f(length);
    string->size = length;
    wcscpy(string->str, str);

    return string;
  }
};

template <typename T> class list {
public:
  uint8_t pad[0x10];
  uint64_t _items;
  int _size;

  T at(int index) {
    if (!_items)
      return T();

    return *(T *)(_items + 0x20 + (index * sizeof(T)));
  }
};
} // namespace system_c

namespace unity {
struct vector2_t {
  float x, y;

  vector2_t() : x(0.f), y(0.f) {};
  vector2_t(float _x, float _y) : x(_x), y(_y) {};

  bool operator==(vector2_t other) {
    return this->x == other.x && this->y == other.y;
  }
};

struct vector3_t {
  float x, y, z;

  vector3_t() : x(0.f), y(0.f), z(0.f) {};
  vector3_t(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

  bool operator==(vector3_t other) {
    return this->x == other.x && this->y == other.y && this->z == other.z;
  }

  float magnitude() {
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
  }

  float distance(vector3_t other) {
    return sqrtf(((this->x - other.x) * (this->x - other.x)) +
                 ((this->y - other.y) * (this->y - other.y)) +
                 ((this->z - other.z) * (this->z - other.z)));
  }
};

class game_object_t;
class component_t;
class transform_t;
class camera_t;

// Read the native engine handle (m_CachedPtr) from any managed Unity Object.
static inline uintptr_t unity_native_handle(const void *managed) {
  if (!is_valid_ptr(managed)) return 0;
  return *(const uintptr_t *)((const uint8_t *)managed + 0x10);
}

// SEH helpers for calling Unity icalls from member functions.
// __try can't live in a function with C++ object unwinding, so these
// are file-static non-member wrappers.
static inline uintptr_t seh_u_u(uintptr_t (*fn)(uintptr_t), uintptr_t a) {
  __try { return fn(a); } __except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}
static inline void seh_sp(void (*fn)(uintptr_t, void *),
                          uintptr_t h, void *v) {
  __try { fn(h, v); } __except (EXCEPTION_EXECUTE_HANDLER) {}
}
static inline void seh_gp(void (*fn)(uintptr_t, void *),
                          uintptr_t h, void *out) {
  __try { fn(h, out); } __except (EXCEPTION_EXECUTE_HANDLER) {}
}

class game_object_t {
public:
  // On Unity 6, Internal_CreateGameObject and Internal_AddComponentWithType are
  // [FreeFunction]s, not icalls — resolve_icall() returns null for them.
  // Use get_method_by_name (SEH-guarded) with an RVA fallback.
  static il2cpp::method_info_t *resolve_gobj_method(const char *name, int argc) {
    __try {
      il2cpp::il2cpp_class_t *go =
          il2cpp::get_class_by_name("GameObject", "UnityEngine");
      if (!go) return nullptr;
      return il2cpp::get_method_by_name(go, name, argc);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
      return nullptr;
    }
  }

  static void *gobj_method_ptr(const char *name, int argc, uint32_t rva) {
    if (il2cpp::method_info_t *m = resolve_gobj_method(name, argc))
      if (void *p = m->get_fn_ptr<void *>()) return p;
    HMODULE ga = GetModuleHandleA("GameAssembly.dll");
    if (ga && rva) return (void *)((uint64_t)ga + rva);
    return nullptr;
  }

  static bool seh_call3(void (*fn)(uint64_t, void *, void *),
                        uint64_t a, void *b, void *c) {
    __try { fn(a, b, c); return true; }
    __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
  }

  static void *seh_call_add(void *(*fn)(game_object_t *,
                                        il2cpp::il2cpp_object_t *, void *),
                            game_object_t *self,
                            il2cpp::il2cpp_object_t *type_obj) {
    __try { return fn(self, type_obj, nullptr); }
    __except (EXCEPTION_EXECUTE_HANDLER) { return nullptr; }
  }

  static game_object_t *create(const wchar_t *name) {
    static void (*create_f)(uint64_t, void *, void *) =
        (decltype(create_f))gobj_method_ptr("Internal_CreateGameObject", 2,
                                            0xB88B5A0);
    if (!create_f) return nullptr;
    il2cpp::il2cpp_class_t *go_class =
        il2cpp::get_class_by_name("GameObject", "UnityEngine");
    if (!go_class) return nullptr;
    uint64_t go = il2cpp::object_new(go_class);
    if (!go) return nullptr;
    system_c::string_t *name_str = system_c::string_t::create_string(name);
    seh_call3(create_f, go, name_str, nullptr);
    return (game_object_t *)go;
  }

  // Returns the new component directly — do NOT call get_component after this.
  // GetComponent_Injected hard-faults from injected-thread context on Unity 6.
  uint64_t add_component(il2cpp::il2cpp_type_t *type) {
    static void *(*add_component_f)(game_object_t *,
                                    il2cpp::il2cpp_object_t *, void *) =
        (decltype(add_component_f))gobj_method_ptr(
            "Internal_AddComponentWithType", 1, 0xB88A020);
    if (!add_component_f) return 0;
    il2cpp::il2cpp_object_t *type_obj = il2cpp::type_get_object(type);
    return (uint64_t)seh_call_add(add_component_f, this, type_obj);
  }

  uintptr_t native_handle() const { return unity_native_handle(this); }

  // Unity 6: get_transform() icall renamed to _Injected, takes native handle.
  transform_t *get_transform() {
    static auto gt_f = (uintptr_t (*)(uintptr_t))il2cpp::resolve_icall(
        "UnityEngine.GameObject::get_transform_Injected(System.IntPtr)");
    if (!gt_f) return nullptr;
    uintptr_t h = native_handle();
    if (!h) return nullptr;
    return (transform_t *)seh_u_u(gt_f, h);
  }

  void dont_destroy_on_load() {
    static auto ddol_f = (void (*)(uintptr_t))il2cpp::resolve_icall(
        "UnityEngine.Object::DontDestroyOnLoad_Injected(System.IntPtr)");
    if (!ddol_f) return;
    uintptr_t h = native_handle();
    if (h) ddol_f(h);
  }
};

class component_t {
public:
  uintptr_t native_handle() const { return unity_native_handle(this); }

  transform_t *get_transform() {
    static auto gt_f = (uintptr_t (*)(uintptr_t))il2cpp::resolve_icall(
        "UnityEngine.Component::get_transform_Injected(System.IntPtr)");
    if (!gt_f) return nullptr;
    uintptr_t h = native_handle();
    if (!h) return nullptr;
    return (transform_t *)seh_u_u(gt_f, h);
  }
};

class transform_t {
public:
  uintptr_t native_handle() const { return unity_native_handle(this); }

  // Unity 6: set_position_Injected takes native IntPtr + Vector3& by ref.
  void set_position(vector3_t position) {
    static auto sp_f = (void (*)(uintptr_t, void *))il2cpp::resolve_icall(
        "UnityEngine.Transform::set_position_Injected(System.IntPtr,"
        "UnityEngine.Vector3&)");
    if (!sp_f) return;
    uintptr_t h = (uintptr_t)this;
    if (h) seh_sp(sp_f, h, &position);
  }

  vector3_t get_position() {
    static auto gp_f = (void (*)(uintptr_t, void *))il2cpp::resolve_icall(
        "UnityEngine.Transform::get_position_Injected(System.IntPtr,"
        "UnityEngine.Vector3&)");
    vector3_t result{};
    if (!gp_f) return result;
    uintptr_t h = native_handle();
    if (h) seh_gp(gp_f, h, &result);
    return result;
  }
};

class camera_t : public component_t {
public:
  static camera_t *get_main() {
    static auto gm_f = (uintptr_t (*)())il2cpp::resolve_icall(
        "UnityEngine.Camera::get_main_Injected()");
    if (!gm_f) return nullptr;
    return (camera_t *)gm_f();
  }
};

class time {
public:
  static float get_fixed_time() {
    static float (*get_fixed_time_f)() =
        (decltype(get_fixed_time_f))il2cpp::resolve_icall(
            "UnityEngine.Time::get_fixedTime()");
    return get_fixed_time_f();
  }
};
} // namespace unity