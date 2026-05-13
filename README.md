# Rust_Dumper

Uses live IL2CPP runtime reflection to dump class offsets, method RVAs, and typeinfo addresses.

-- HEADS UP --  Need to create C:\dumps before running it as it does not create the folder for you. 

## How it works

**Injection** – The DLL gets injected into Rust. Nothing fancy; you're supposed to have EAC turned off.

**Class discovery** – `dumper::produce()` walks through the live IL2CPP domain (`il2cpp_domain_get` -> assemblies -> images) and finds classes by name using `get_class_by_name`. You don't need to feed it any pre-generated metadata files.

**Offset resolution** – For each class, it reads field offsets and static field offsets straight from the live `Il2CppClass*` and `FieldInfo*` structs using the `il2cpp_lib.hpp` helpers (`get_field_by_name`, `get_field_from_field_type_class`, `get_static_field_if_value_is`, etc.).

**Method RVAs** – Method pointers get resolved through `get_method_by_name`, then converted to RVAs relative to `GameAssembly.dll` base.

**TypeDefinitionIndex** – Found by scanning the `Il2CppClass` struct bytes at offsets `0x100–0x140` for a TypeDef metadata token (high byte `0x02`, non-zero row). No external metadata file or type table scan required.

**Typeinfo RVA** – Found by scanning the `.data` section of `GameAssembly.dll` at runtime for the `Il2CppClass*` pointer. The address of the matching slot minus the module base gives the typeinfo RVA. This works for all classes including obfuscated ones (the `%hash` named classes) with no inspector dump or pre-generated header needed.

**Output** – Everything gets written to `C:\dumps\dumper_output.h` as a C++ header.

## Usage

Inject Rust_Dumper.dll into RustClient.exe while in a server (not sitting at the main menu). Once the dump finishes, check `C:\dumps\` for the output files. Have a weapon in your hands and full hotbar preferably.

## Notes

Classes with obfuscated names (the `%hash` ones) are found by walking parent chains or matching field types instead of relying on direct name lookup.

Generic inflated instances like `ListComponent<UIChat>` get resolved by walking up the parent chain from a known concrete class.

`TypeDefinitionIndex` values tend to hold up across minor game patches as long as the metadata order doesn't get shuffled around.

Typeinfo RVAs are discovered purely at runtime — The `.data` section scan finds the correct slot for every class, including obfuscated ones.

## Credits

Thank you to Serotonin devs, whomever made it.

My original git got so messed up i made a new one, sorry to the people that forked
