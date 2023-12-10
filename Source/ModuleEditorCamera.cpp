#include "ModuleEditorCamera.h"
#include "GL/glew.h"

ModuleEditorCamera::ModuleEditorCamera()
{
}

ModuleEditorCamera::~ModuleEditorCamera()
{
}

bool ModuleEditorCamera::Init()
{
	frustum.SetKind(FrustumSpaceGL, FrustumRightHanded);
	SetPlaneDistances(0.1f, 200.0f);
	SetFOV(90.0f);
	SetAspectRatio(1.3f);
	SetPosition(float3(0.0f, 1.0f, -2.0f));
	LookAt(float3::unitZ.x, float3::unitZ.y, float3::unitZ.z);
	SetOrientation(float3::unitY);

	return true;
}

void ModuleEditorCamera::SetFOV(float fovValue)
{
	fov = DegToRad(fovValue);
	frustum.SetHorizontalFovAndAspectRatio(fov, aspectRatio);
}

void ModuleEditorCamera::SetAspectRatio(float aRatio)
{
	aspectRatio = aRatio;
	frustum.SetHorizontalFovAndAspectRatio(fov, aspectRatio);
}

void ModuleEditorCamera::SetPlaneDistances(float nearPlane, float farPlane)
{
	frustum.SetViewPlaneDistances(nearPlane, farPlane);
}

void ModuleEditorCamera::SetPosition(float3 pos)
{
	frustum.SetPos(pos);
}

void ModuleEditorCamera::SetOrientation(float3 dir)
{
	frustum.SetUp(dir);
}

void ModuleEditorCamera::LookAt(float x, float y, float z)
{
	frustum.SetFront(float3(x, y, z));
}

float4x4 ModuleEditorCamera::GetProjectionMatrixTransposed()
{
	return frustum.ProjectionMatrix().Transposed();
}

float4x4 ModuleEditorCamera::GetViewMatrixTransposed()
{
	return float4x4(frustum.ViewMatrix()).Transposed();
}

