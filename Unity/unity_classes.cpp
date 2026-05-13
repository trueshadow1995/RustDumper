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
    DUMP_METHOD_BY_ICALL(
        Destroy,
        "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)");
    DUMP_METHOD_BY_ICALL(DestroyImmediate,
                         "UnityEngine.Object::DestroyImmediate(UnityEngine."
                         "Object,System.Boolean)");
    DUMP_METHOD_BY_ICALL(
        DontDestroyOnLoad,
        "UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
    DUMP_METHOD_BY_ICALL(
        FindObjectFromInstanceID,
        "UnityEngine.Object::FindObjectFromInstanceID(System.Int32)");
    DUMP_METHOD_BY_ICALL(GetName,
                         "UnityEngine.Object::GetName(UnityEngine.Object)");
    DUMP_METHOD_BY_ICALL(get_hideFlags, "UnityEngine.Object::get_hideFlags()");
    DUMP_METHOD_BY_ICALL(
        set_hideFlags,
        "UnityEngine.Object::set_hideFlags(UnityEngine.HideFlags)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("GameObject", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(SetActive,
                         "UnityEngine.GameObject::SetActive(System.Boolean)");
    DUMP_METHOD_BY_ICALL(
        Internal_AddComponentWithType,
        "UnityEngine.GameObject::Internal_AddComponentWithType(System.Type)");
    DUMP_METHOD_BY_ICALL(GetComponent,
                         "UnityEngine.GameObject::GetComponent(System.Type)");
    DUMP_METHOD_BY_ICALL(GetComponentCount,
                         "UnityEngine.GameObject::GetComponentCount()");
    DUMP_METHOD_BY_ICALL(GetComponentInChildren,
                         "UnityEngine.GameObject::GetComponentInChildren("
                         "System.Type,System.Boolean)");
    DUMP_METHOD_BY_ICALL(GetComponentInParent,
                         "UnityEngine.GameObject::GetComponentInParent(System."
                         "Type,System.Boolean)");
    DUMP_METHOD_BY_ICALL(
        GetComponentsInternal,
        "UnityEngine.GameObject::GetComponentsInternal(System.Type,System."
        "Boolean,System.Boolean,System.Boolean,System.Boolean,System.Object)");
    DUMP_METHOD_BY_ICALL(Internal_CreateGameObject,
                         "UnityEngine.GameObject::Internal_CreateGameObject("
                         "UnityEngine.GameObject,System.String)");
    DUMP_METHOD_BY_ICALL(get_layer, "UnityEngine.GameObject::get_layer()");
    DUMP_METHOD_BY_ICALL(get_tag, "UnityEngine.GameObject::get_tag()");
    DUMP_METHOD_BY_ICALL(get_transform,
                         "UnityEngine.GameObject::get_transform()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Component", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_gameObject,
                         "UnityEngine.Component::get_gameObject()");
    DUMP_METHOD_BY_ICALL(get_transform,
                         "UnityEngine.Component::get_transform()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Behaviour", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_enabled, "UnityEngine.Behaviour::get_enabled()");
    DUMP_METHOD_BY_ICALL(set_enabled,
                         "UnityEngine.Behaviour::set_enabled(System.Boolean)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Transform", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(get_eulerAngles);
    DUMP_METHOD_BY_ICALL(GetChild,
                         "UnityEngine.Transform::GetChild(System.Int32)");
    DUMP_METHOD_BY_ICALL(GetParent, "UnityEngine.Transform::GetParent()");
    DUMP_METHOD_BY_ICALL(GetRoot, "UnityEngine.Transform::GetRoot()");
    DUMP_METHOD_BY_ICALL(InverseTransformDirection_Injected,
                         "UnityEngine.Transform::InverseTransformDirection_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(InverseTransformPoint_Injected,
                         "UnityEngine.Transform::InverseTransformPoint_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(InverseTransformVector_Injected,
                         "UnityEngine.Transform::InverseTransformVector_"
                         "Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(GetPositionAndRotation,
                         "UnityEngine.Transform::GetPositionAndRotation("
                         "UnityEngine.Vector3&,UnityEngine.Quaternion&)");
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
    DUMP_METHOD_BY_ICALL(get_childCount,
                         "UnityEngine.Transform::get_childCount()");
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
    DUMP_METHOD_BY_ICALL(
        WorldToScreenPoint_Injected,
        "UnityEngine.Camera::WorldToScreenPoint_Injected(UnityEngine.Vector3&,"
        "UnityEngine.Camera/MonoOrStereoscopicEye,UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(GetAllCamerasCount,
                         "UnityEngine.Camera::GetAllCamerasCount()");
    DUMP_METHOD_BY_ICALL(CopyFrom,
                         "UnityEngine.Camera::CopyFrom(UnityEngine.Camera)");
    DUMP_METHOD_BY_ICALL(set_cullingMask,
                         "UnityEngine.Camera::set_cullingMask(System.Int32)");
    DUMP_METHOD_BY_ICALL(
        set_clearFlags,
        "UnityEngine.Camera::set_clearFlags(UnityEngine.CameraClearFlags)");
    DUMP_METHOD_BY_ICALL(
        set_backgroundColor_Injected,
        "UnityEngine.Camera::set_backgroundColor_Injected(UnityEngine.Color&)");
    DUMP_METHOD_BY_ICALL(
        set_targetTexture,
        "UnityEngine.Camera::set_targetTexture(UnityEngine.RenderTexture)");
    DUMP_METHOD_BY_ICALL(Render, "UnityEngine.Camera::Render()");
    DUMP_METHOD_BY_ICALL(RenderWithShader,
                         "UnityEngine.Camera::RenderWithShader(UnityEngine."
                         "Shader,System.String)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Time", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_deltaTime, "UnityEngine.Time::get_deltaTime()");
    DUMP_METHOD_BY_ICALL(get_fixedDeltaTime,
                         "UnityEngine.Time::get_fixedDeltaTime()");
    DUMP_METHOD_BY_ICALL(get_fixedTime, "UnityEngine.Time::get_fixedTime()");
    DUMP_METHOD_BY_ICALL(get_frameCount, "UnityEngine.Time::get_frameCount()");
    DUMP_METHOD_BY_ICALL(get_realtimeSinceStartup,
                         "UnityEngine.Time::get_realtimeSinceStartup()");
    DUMP_METHOD_BY_ICALL(get_smoothDeltaTime,
                         "UnityEngine.Time::get_smoothDeltaTime()");
    DUMP_METHOD_BY_ICALL(get_time, "UnityEngine.Time::get_time()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Material", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(
        SetFloatImpl,
        "UnityEngine.Material::SetFloatImpl(System.Int32,System.Single)");
    DUMP_METHOD_BY_ICALL(SetColorImpl_Injected,
                         "UnityEngine.Material::SetColorImpl_Injected(System."
                         "Int32,UnityEngine.Color&)");
    DUMP_METHOD_BY_ICALL(SetTextureImpl,
                         "UnityEngine.Material::SetTextureImpl(System.Int32,"
                         "UnityEngine.Texture)");
    DUMP_METHOD_BY_ICALL(CreateWithMaterial,
                         "UnityEngine.Material::CreateWithMaterial(UnityEngine."
                         "Material,UnityEngine.Material)");
    DUMP_METHOD_BY_ICALL(CreateWithShader,
                         "UnityEngine.Material::CreateWithShader(UnityEngine."
                         "Material,UnityEngine.Shader)");
    DUMP_METHOD_BY_ICALL(SetBufferImpl,
                         "UnityEngine.Material::SetBufferImpl(System.Int32,"
                         "UnityEngine.ComputeBuffer)");
    DUMP_METHOD_BY_ICALL(
        set_shader, "UnityEngine.Material::set_shader(UnityEngine.Shader)");
    DUMP_METHOD_BY_ICALL(get_shader, "UnityEngine.Material::get_shader()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("MaterialPropertyBlock",
                                           "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR(ctor, ".ctor");
    DUMP_METHOD_BY_ICALL(SetFloatImpl,
                         "UnityEngine.MaterialPropertyBlock::SetFloatImpl("
                         "System.Int32,System.Single)");
    DUMP_METHOD_BY_ICALL(SetTextureImpl,
                         "UnityEngine.MaterialPropertyBlock::SetTextureImpl("
                         "System.Int32,UnityEngine.Texture)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Shader", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(Find);
    DUMP_METHOD_BY_ICALL(PropertyToID,
                         "UnityEngine.Shader::PropertyToID(System.String)");
    DUMP_METHOD_BY_ICALL(GetPropertyCount,
                         "UnityEngine.Shader::GetPropertyCount()");
    DUMP_METHOD_BY_ICALL(
        GetPropertyName,
        "UnityEngine.Shader::GetPropertyName(UnityEngine.Shader,System.Int32)");
    DUMP_METHOD_BY_ICALL(
        GetPropertyType,
        "UnityEngine.Shader::GetPropertyType(UnityEngine.Shader,System.Int32)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Mesh", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(Internal_Create,
                         "UnityEngine.Mesh::Internal_Create(UnityEngine.Mesh)");
    DUMP_METHOD_BY_ICALL(MarkDynamicImpl,
                         "UnityEngine.Mesh::MarkDynamicImpl()");
    DUMP_METHOD_BY_ICALL(ClearImpl,
                         "UnityEngine.Mesh::ClearImpl(System.Boolean)");
    DUMP_METHOD_BY_ICALL(set_subMeshCount,
                         "UnityEngine.Mesh::set_subMeshCount(System.Int32)");
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
    DUMP_METHOD_BY_ICALL(
        UploadMeshDataImpl,
        "UnityEngine.Mesh::UploadMeshDataImpl(System.Boolean)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Renderer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_enabled, "UnityEngine.Renderer::get_enabled()");
    DUMP_METHOD_BY_ICALL(get_isVisible,
                         "UnityEngine.Renderer::get_isVisible()");
    DUMP_METHOD_BY_ICALL(GetMaterial, "UnityEngine.Renderer::GetMaterial()");
    DUMP_METHOD_BY_ICALL(GetMaterialArray,
                         "UnityEngine.Renderer::GetMaterialArray()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Texture", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(
        set_filterMode,
        "UnityEngine.Texture::set_filterMode(UnityEngine.FilterMode)");
    DUMP_METHOD_BY_ICALL(GetNativeTexturePtr,
                         "UnityEngine.Texture::GetNativeTexturePtr()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Texture2D", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 9);
    DUMP_METHOD_BY_ICALL(
        Internal_CreateImpl,
        "UnityEngine.Texture2D::Internal_CreateImpl(UnityEngine.Texture2D,"
        "System.Int32,System.Int32,System.Int32,UnityEngine.Experimental."
        "Rendering.GraphicsFormat,UnityEngine.TextureColorSpace,UnityEngine."
        "Experimental.Rendering.TextureCreationFlags,System.IntPtr,System."
        "String)");
    DUMP_METHOD_BY_ICALL(GetRawImageDataSize,
                         "UnityEngine.Texture2D::GetRawImageDataSize()");
    DUMP_METHOD_BY_ICALL(
        GetWritableImageData,
        "UnityEngine.Texture2D::GetWritableImageData(System.Int32)");
    DUMP_METHOD_BY_ICALL(
        ApplyImpl,
        "UnityEngine.Texture2D::ApplyImpl(System.Boolean,System.Boolean)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Sprite", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_texture, "UnityEngine.Sprite::get_texture()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("RenderTexture", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(GetTemporary, "GetTemporary", 3);
    DUMP_METHOD_BY_ICALL(ReleaseTemporary,
                         "UnityEngine.RenderTexture::ReleaseTemporary("
                         "UnityEngine.RenderTexture)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("CommandBuffer",
                                           "UnityEngine.Rendering");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR(ctor, ".ctor");
    DUMP_METHOD_BY_ICALL(Clear, "UnityEngine.Rendering.CommandBuffer::Clear()");
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
    DUMP_METHOD_BY_ICALL(
        DisableScissorRect,
        "UnityEngine.Rendering.CommandBuffer::DisableScissorRect()");
    DUMP_METHOD_BY_ICALL(Internal_DrawProceduralIndexedIndirect_Injected,
                         "UnityEngine.Rendering.CommandBuffer::Internal_"
                         "DrawProceduralIndexedIndirect_Injected()");
    DUMP_METHOD_BY_ICALL(
        Internal_DrawMesh_Injected,
        "UnityEngine.Rendering.CommandBuffer::Internal_DrawMesh_Injected("
        "UnityEngine.Mesh,UnityEngine.Matrix4x4&,UnityEngine.Material,System."
        "Int32,System.Int32,UnityEngine.MaterialPropertyBlock)")
    DUMP_METHOD_BY_ICALL(
        Internal_DrawRenderer,
        "UnityEngine.Rendering.CommandBuffer::Internal_DrawRenderer("
        "UnityEngine.Renderer,UnityEngine.Material,System.Int32,System.Int32)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("RenderTargetIdentifier",
                                           "UnityEngine.Rendering")
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_PARAM_NAME(ctor, ".ctor", "tex", 0);
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("ComputeBuffer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 5);
    DUMP_METHOD_BY_ICALL(get_count, "UnityEngine.ComputeBuffer::get_count()");
    DUMP_METHOD_BY_NAME(Release);
    DUMP_METHOD_BY_ICALL(
        InternalSetNativeData,
        "UnityEngine.ComputeBuffer::InternalSetNativeData(System.IntPtr,System."
        "Int32,System.Int32,System.Int32,System.Int32)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("GraphicsBuffer", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(ctor, ".ctor", 3);
    DUMP_METHOD_BY_ICALL(get_count, "UnityEngine.GraphicsBuffer::get_count()");
    DUMP_METHOD_BY_NAME_STR_ARG_CT(Dispose, "Dispose", 0);
    DUMP_METHOD_BY_ICALL(
        InternalSetNativeData,
        "UnityEngine.GraphicsBuffer::InternalSetNativeData(System.IntPtr,"
        "System.Int32,System.Int32,System.Int32,System.Int32)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Event", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_NAME(get_current);
    DUMP_METHOD_BY_ICALL(get_type, "UnityEngine.Event::get_type()");
    DUMP_METHOD_BY_ICALL(PopEvent,
                         "UnityEngine.Event::PopEvent(UnityEngine.Event)");
    DUMP_METHOD_BY_ICALL(Internal_Use, "UnityEngine.Event::Internal_Use()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Graphics", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(Internal_BlitMaterial5,
                         "UnityEngine.Graphics::Internal_BlitMaterial5("
                         "UnityEngine.Texture,UnityEngine.RenderTexture,"
                         "UnityEngine.Material,System.Int32,System.Boolean)");
    DUMP_METHOD_BY_ICALL(ExecuteCommandBuffer,
                         "UnityEngine.Graphics::ExecuteCommandBuffer("
                         "UnityEngine.Rendering.CommandBuffer)");
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
    DUMP_METHOD_BY_ICALL(LoadFromFile_Internal,
                         "UnityEngine.AssetBundle::LoadFromFile_Internal("
                         "System.String,System.UInt32,System.UInt64)");
    DUMP_METHOD_BY_ICALL(LoadAsset_Internal,
                         "UnityEngine.AssetBundle::LoadAsset_Internal(System."
                         "String,System.Type)");
    DUMP_METHOD_BY_ICALL(Unload,
                         "UnityEngine.AssetBundle::Unload(System.Boolean)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Screen", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_width, "UnityEngine.Screen::get_width()");
    DUMP_METHOD_BY_ICALL(get_height, "UnityEngine.Screen::get_height()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Input", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(
        get_mousePosition_Injected,
        "UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)");
    DUMP_METHOD_BY_ICALL(get_mouseScrollDelta_Injected,
                         "UnityEngine.Input::get_mouseScrollDelta_Injected("
                         "UnityEngine.Vector2&)");
    DUMP_METHOD_BY_ICALL(GetMouseButtonDown,
                         "UnityEngine.Input::GetMouseButtonDown(System.Int32)");
    DUMP_METHOD_BY_ICALL(GetMouseButtonUp,
                         "UnityEngine.Input::GetMouseButtonUp(System.Int32)");
    DUMP_METHOD_BY_ICALL(GetMouseButton,
                         "UnityEngine.Input::GetMouseButton(System.Int32)");
    DUMP_METHOD_BY_ICALL(
        GetKeyDownInt, "UnityEngine.Input::GetKeyDownInt(UnityEngine.KeyCode)");
    DUMP_METHOD_BY_ICALL(GetKeyUpInt,
                         "UnityEngine.Input::GetKeyUpInt(UnityEngine.KeyCode)");
    DUMP_METHOD_BY_ICALL(GetKeyInt,
                         "UnityEngine.Input::GetKeyInt(UnityEngine.KeyCode)");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Application", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_version, "UnityEngine.Application::get_version()");
    DUMP_METHOD_BY_ICALL(Quit, "UnityEngine.Application::Quit(System.Int32)");
    DUMP_METHOD_BY_ICALL(get_isFocused,
                         "UnityEngine.Application::get_isFocused()");
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
    DUMP_METHOD_BY_ICALL(get_INTERNAL_defaultRenderPipeline,
                         "UnityEngine.Rendering.GraphicsSettings::get_INTERNAL_"
                         "defaultRenderPipeline()");
    DUMPER_CLASS_END;

    DUMPER_CLASS_BEGIN_FROM_NAME_NAMESPACE("Cursor", "UnityEngine");
    DUMPER_SECTION("Functions");
    DUMP_METHOD_BY_ICALL(get_visible, "UnityEngine.Cursor::get_visible()");
    DUMPER_CLASS_END;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    printf("[Rust Dumper] Exception during Unity class dumping\n");
    write_to_log("[ERROR] Exception occurred while dumping Unity classes\n");
  }
  printf("[Rust Dumper] Unity class dumping complete\n");
}
