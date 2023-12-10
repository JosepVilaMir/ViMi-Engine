#pragma once
#include "Module.h"
#include "MathGeoLib/include/MathGeoLib.h"

class ModuleEditorCamera : public Module
{
public:
	ModuleEditorCamera();
	~ModuleEditorCamera();

	bool Init();

	void SetFOV(float fov);
	void SetAspectRatio(float aRatio);
	void SetPlaneDistances(float nearPlane, float farPlane);
	void SetPosition(float3 pos);
	void SetOrientation(float3 dir);
	void LookAt(float x, float y, float z);
	float4x4 GetProjectionMatrixTransposed();
	float4x4 GetViewMatrixTransposed();

private:
	Frustum frustum;
	float fov;
	float aspectRatio;
};

