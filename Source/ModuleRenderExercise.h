#pragma once
#include "Module.h"
#include "MathGeoLib/include/MathGeoLib.h"

class ModuleRenderExercise : public Module
{
public:
	ModuleRenderExercise();
	~ModuleRenderExercise();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	float4x4 GetMVP();

private:
	unsigned int shaderProgram;
	unsigned int VBO, VAO;
	float4x4 model;
	float4x4 view;
	float4x4 proj;
	float4x4 mvp;
};

