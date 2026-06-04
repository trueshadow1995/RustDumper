#include "dumper.hpp"
#include "dumper_macros.hpp"
#include "util.hpp"

void dumper::produce_unity() {
  printf("[Rust Dumper] Writing Unity classes...\n");
  write_to_log("[UNITY] Starting Unity class dump...\n");

  __try {
    write_to_log("[UNITY] Dumping Object class...\n");
    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Object", "UnityEngine");
    DUMPER_SECTION("Offsets");
    DUMP_MEMBER_BY_NAME(m_CachedPtr);
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(GetInstanceID);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Destroy, "Destroy", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(DestroyImmediate, "DestroyImmediate", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(DontDestroyOnLoad, "DontDestroyOnLoad", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(FindObjectFromInstanceID,
                                   "FindObjectFromInstanceID", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetName, "GetName", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_hideFlags, "get_hideFlags", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_hideFlags, "set_hideFlags", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("GameObject", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetActive, "SetActive", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_AddComponentWithType,
                                   "Internal_AddComponentWithType", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetComponent, "GetComponent", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetComponentCount, "GetComponentCount", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetComponentInChildren,
                                   "GetComponentInChildren", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetComponentInParent, "GetComponentInParent",
                                   2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetComponentsInternal,
                                   "GetComponentsInternal", 6);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_CreateGameObject,
                                   "Internal_CreateGameObject", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_layer, "get_layer", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_tag, "get_tag", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_transform, "get_transform", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Component", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_gameObject, "get_gameObject", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_transform, "get_transform", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Behaviour", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_enabled, "get_enabled", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_enabled, "set_enabled", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Transform", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(get_eulerAngles);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetChild, "GetChild", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetParent, "GetParent", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetRoot, "GetRoot", 0);
    DUMP_METHOD_BY_ICALL(InverseTransformDirection_Injected,
                         "UnityEngine.Transform::InverseTransformDirection_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(InverseTransformPoint_Injected,
                         "UnityEngine.Transform::InverseTransformPoint_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(InverseTransformVector_Injected,
                         "UnityEngine.Transform::InverseTransformVector_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetPositionAndRotation,
                                   "GetPositionAndRotation", 2);
    DUMP_METHOD_BY_ICALL(
        SetLocalPositionAndRotation_Injected,
        "UnityEngine.Transform::SetLocalPositionAndRotation_Injected("
        "UnityEngine.Vector3&,UnityEngine.Quaternion&)");
    DUMP_METHOD_BY_ICALL(
        SetPositionAndRotation_Injected,
        "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine."
        "Vector3&,UnityEngine.Quaternion&)");
    DUMP_METHOD_BY_ICALL(TransformDirection_Injected,
                         "UnityEngine.Transform::TransformDirection_Injected("
                         "UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(TransformPoint_Injected,
                         "UnityEngine.Transform::TransformPoint_Injected("
                         "UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(TransformVector_Injected,
                         "UnityEngine.Transform::TransformVector_Injected("
                         "UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_childCount, "get_childCount", 0);
    DUMP_METHOD_BY_ICALL(get_forward_Injected,
                         "UnityEngine.Transform::get_forward_Injected("
                         "UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_right_Injected,
                         "UnityEngine.Transform::get_right_Injected("
                         "UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_up_Injected,
                         "UnityEngine.Transform::get_up_Injected("
                         "UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_localPosition_Injected,
                         "UnityEngine.Transform::get_localPosition_Injected("
                         "UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_localRotation_Injected,
                         "UnityEngine.Transform::get_localRotation_Injected("
                         "UnityEngine.Quaternion&)");
    DUMP_METHOD_BY_ICALL(
        get_localScale_Injected,
        "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(
        get_lossyScale_Injected,
        "UnityEngine.Transform::get_lossyScale_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(
        get_position_Injected,
        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_rotation_Injected,
                         "UnityEngine.Transform::get_rotation_Injected("
                         "UnityEngine.Quaternion&)");
    DUMP_METHOD_BY_ICALL(set_localPosition_Injected,
                         "UnityEngine.Transform::set_localPosition_Injected("
                         "UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(set_localRotation_Injected,
                         "UnityEngine.Transform::set_localRotation_Injected("
                         "UnityEngine.Quaternion&)");
    DUMP_METHOD_BY_ICALL(
        set_localScale_Injected,
        "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(
        set_position_Injected,
        "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(set_rotation_Injected,
                         "UnityEngine.Transform::set_rotation_Injected("
                         "UnityEngine.Quaternion&)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Camera", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_main, "get_main", 0);
    DUMP_METHOD_BY_ICALL(
        WorldToScreenPoint_Injected,
        "UnityEngine.Camera::WorldToScreenPoint_Injected(UnityEngine.Vector3&,"
        "UnityEngine.Camera/MonoOrStereoscopicEye,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(
        ScreenToWorldPoint_Injected,
        "UnityEngine.Camera::ScreenToWorldPoint_Injected(UnityEngine.Vector3&,"
        "UnityEngine.Camera/MonoOrStereoscopicEye,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetAllCamerasCount, "GetAllCamerasCount", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(CopyFrom, "CopyFrom", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_fieldOfView, "get_fieldOfView", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_fieldOfView, "set_fieldOfView", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_nearClipPlane, "get_nearClipPlane", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_nearClipPlane, "set_nearClipPlane", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_farClipPlane, "get_farClipPlane", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_farClipPlane, "set_farClipPlane", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_depth, "get_depth", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_depth, "set_depth", 1);
    DUMP_METHOD_BY_ICALL(get_projectionMatrix_Injected,
                         "UnityEngine.Camera::get_projectionMatrix_Injected("
                         "UnityEngine.Matrix4x4&)");
    DUMP_METHOD_BY_ICALL(set_projectionMatrix_Injected,
                         "UnityEngine.Camera::set_projectionMatrix_Injected("
                         "UnityEngine.Matrix4x4&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_cullingMask, "set_cullingMask", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_clearFlags, "set_clearFlags", 1);
    DUMP_METHOD_BY_ICALL(
        set_backgroundColor_Injected,
        "UnityEngine.Camera::set_backgroundColor_Injected(UnityEngine.Color&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_targetTexture, "set_targetTexture", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Render, "Render", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(RenderWithShader, "RenderWithShader", 2);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Time", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_deltaTime, "get_deltaTime", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_fixedDeltaTime, "get_fixedDeltaTime", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_fixedTime, "get_fixedTime", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_frameCount, "get_frameCount", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_realtimeSinceStartup,
                                   "get_realtimeSinceStartup", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_smoothDeltaTime, "get_smoothDeltaTime",
                                   0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_time, "get_time", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Material", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetFloatImpl, "SetFloatImpl", 2);
    DUMP_METHOD_BY_ICALL(SetColorImpl_Injected,
                         "UnityEngine.Material::SetColorImpl_Injected(System."
                         "Int32,UnityEngine.Color&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetTextureImpl, "SetTextureImpl", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(CreateWithMaterial, "CreateWithMaterial", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(CreateWithShader, "CreateWithShader", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetBufferImpl, "SetBufferImpl", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_shader, "set_shader", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_shader, "get_shader", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("MaterialPropertyBlock",
                                           "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR(ctor, ".ctor");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetFloatImpl, "SetFloatImpl", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(SetTextureImpl, "SetTextureImpl", 2);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Shader", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(Find);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(PropertyToID, "PropertyToID", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetPropertyCount, "GetPropertyCount", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetPropertyName, "GetPropertyName", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetPropertyType, "GetPropertyType", 2);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Mesh", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_Create, "Internal_Create", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(MarkDynamicImpl, "MarkDynamicImpl", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ClearImpl, "ClearImpl", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_subMeshCount, "set_subMeshCount", 1);
    DUMP_METHOD_BY_ICALL(SetVertexBufferParamsFromPtr,
                         "UnityEngine.Mesh::SetVertexBufferParamsFromPtr");
    DUMP_METHOD_BY_ICALL(SetIndexBufferParams,
                         "UnityEngine.Mesh::SetIndexBufferParams");
    DUMP_METHOD_BY_ICALL(InternalSetVertexBufferData,
                         "UnityEngine.Mesh::InternalSetVertexBufferData");
    DUMP_METHOD_BY_ICALL(InternalSetIndexBufferData,
                         "UnityEngine.Mesh::InternalSetIndexBufferData");
    DUMP_METHOD_BY_ICALL(
        SetAllSubMeshesAtOnceFromNativeArray,
        "UnityEngine.Mesh::SetAllSubMeshesAtOnceFromNativeArray");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(UploadMeshDataImpl, "UploadMeshDataImpl", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Renderer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_enabled, "get_enabled", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_isVisible, "get_isVisible", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetMaterial, "GetMaterial", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetMaterialArray, "GetMaterialArray", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Texture", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(set_filterMode, "set_filterMode", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetNativeTexturePtr, "GetNativeTexturePtr",
                                   0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Texture2D", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 9);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_CreateImpl, "Internal_CreateImpl",
                                   9);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetRawImageDataSize, "GetRawImageDataSize",
                                   0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetWritableImageData, "GetWritableImageData",
                                   1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ApplyImpl, "ApplyImpl", 2);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Sprite", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_texture, "get_texture", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("RenderTexture", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetTemporary, "GetTemporary", 3);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ReleaseTemporary, "ReleaseTemporary", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("CommandBuffer",
                                           "UnityEngine.Rendering");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR(ctor, ".ctor");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Clear, "Clear", 0);
    DUMP_METHOD_BY_ICALL(
        SetRenderTargetSingle_Internal_Injected,
        "UnityEngine.Rendering.CommandBuffer::SetRenderTargetSingle_Internal_"
        "Injected( "
        "UnityEngine.Rendering.RenderTargetIdentifier&,UnityEngine.Rendering."
        "RenderBufferLoadAction,UnityEngine.Rendering.RenderBufferStoreAction,"
        "UnityEngine.Rendering.RenderBufferLoadAction,UnityEngine.Rendering."
        "RenderBufferStoreAction)");
    DUMP_METHOD_BY_ICALL(
        ClearRenderTarget_Injected,
        "UnityEngine.Rendering.CommandBuffer::ClearRenderTarget_Injected("
        "UnityEngine.Rendering.RTClearFlags,UnityEngine.Color&,System.Single,"
        "System.UInt32)");
    DUMP_METHOD_BY_ICALL(SetViewport_Injected,
                         "UnityEngine.Rendering.CommandBuffer::SetViewport_"
                         "Injected(UnityEngine.Rect&)");
    DUMP_METHOD_BY_ICALL(
        SetViewProjectionMatrices_Injected,
        "UnityEngine.Rendering.CommandBuffer::SetViewProjectionMatrices_"
        "Injected(UnityEngine.Matrix4x4&,UnityEngine.Matrix4x4&)");
    DUMP_METHOD_BY_ICALL(EnableScissorRect_Injected,
                         "UnityEngine.Rendering.CommandBuffer::"
                         "EnableScissorRect_Injected(UnityEngine.Rect&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(DisableScissorRect, "DisableScissorRect", 0);
    DUMP_METHOD_BY_ICALL(Internal_DrawProceduralIndexedIndirect_Injected,
                         "UnityEngine.Rendering.CommandBuffer::Internal_"
                         "DrawProceduralIndexedIndirect_Injected()");
    DUMP_METHOD_BY_ICALL(
        Internal_DrawMesh_Injected,
        "UnityEngine.Rendering.CommandBuffer::Internal_DrawMesh_Injected("
        "UnityEngine.Mesh,UnityEngine.Matrix4x4&,UnityEngine.Material,System."
        "Int32,System.Int32,UnityEngine.MaterialPropertyBlock)")
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_DrawRenderer,
                                   "Internal_DrawRenderer", 4);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("RenderTargetIdentifier",
                                           "UnityEngine.Rendering")
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_PARAM_NAME(ctor, ".ctor", "tex", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("ComputeBuffer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 5);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_count, "get_count", 0);
    DUMP_METHOD_BY_NAME(Release);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(InternalSetNativeData,
                                   "InternalSetNativeData", 5);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("GraphicsBuffer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 3);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_count, "get_count", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Dispose, "Dispose", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(InternalSetNativeData,
                                   "InternalSetNativeData", 5);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Event", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(get_current);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_type, "get_type", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(PopEvent, "PopEvent", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_Use, "Internal_Use", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Graphics", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Internal_BlitMaterial5,
                                   "Internal_BlitMaterial5", 5);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ExecuteCommandBuffer, "ExecuteCommandBuffer",
                                   1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Matrix4x4", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(Ortho_Injected,
                         "UnityEngine.Matrix4x4::Ortho_Injected(System.Single,"
                         "System.Single,System.Single,System.Single,System."
                         "Single,System.Single,UnityEngine.Matrix4x4&)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("AssetBundle", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(LoadFromMemory_Internal,
                         "UnityEngine.AssetBundle::LoadFromMemory_Internal");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(LoadFromFile_Internal,
                                   "LoadFromFile_Internal", 3);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(LoadAsset_Internal, "LoadAsset_Internal", 2);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Unload, "Unload", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Screen", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_width, "get_width", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_height, "get_height", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Input", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(
        get_mousePosition_Injected,
        "UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_mouseScrollDelta_Injected,
                         "UnityEngine.Input::get_mouseScrollDelta_Injected("
                         "UnityEngine.Vector2&)");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetMouseButtonDown, "GetMouseButtonDown", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetMouseButtonUp, "GetMouseButtonUp", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetMouseButton, "GetMouseButton", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetKeyDownInt, "GetKeyDownInt", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetKeyUpInt, "GetKeyUpInt", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetKeyInt, "GetKeyInt", 1);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Application", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_version, "get_version", 0);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Quit, "Quit", 1);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_isFocused, "get_isFocused", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Gradient", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(SetKeys,
                         "UnityEngine.Gradient::SetKeys(UnityEngine."
                         "GradientColorKey[],UnityEngine.GradientAlphaKey[]");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Physics", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Raycast, "Raycast", 6);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(RaycastNonAlloc, "RaycastNonAlloc", 6);
    DUMP_METHOD_BY_NAME_STR_ARG_CT(CheckCapsule, "CheckCapsule", 5);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Image", "UnityEngine.UI");
    DUMPER_SECTION("Offsets");
    DUMP_MEMBER_BY_NAME(m_Sprite);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("GraphicsSettings",
                                           "UnityEngine.Rendering");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_INTERNAL_defaultRenderPipeline,
                                   "get_INTERNAL_defaultRenderPipeline", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Cursor", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(get_visible, "get_visible", 0);
    DUMPER_CLASS_END;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    printf("[Rust Dumper] Exception during Unity class dumping\n");
    write_to_log("[ERROR] Exception occurred while dumping Unity classes\n");
  }
  printf("[Rust Dumper] Unity class dumping complete\n");
}