#include "ModuleRenderExercise.h"
#include "Application.h"
#include <GL/glew.h>
#include <iostream>
#include "ModuleWindow.h"
#include "ModuleProgram.h"
#include "ModuleEditor.h"
#include "ModuleEditorCamera.h"
#include "SDL.h"
#include "MathGeoLib/include/MathGeoLib.h"


ModuleRenderExercise::ModuleRenderExercise()
{
}

ModuleRenderExercise::~ModuleRenderExercise()
{
}

bool ModuleRenderExercise::Init()
{
    // Triangle definition
    float vertices[] = {
    -0.5, -0.5, 0,
     0.5, -0.5, 0,
     0,  0.5, 0
    };

    // Loads a triangle into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Creates a program with Hello World vertex and fragment shaders
    shaderProgram = App->GetProgram()->CreateProgram("Shaders/vertex_shader.glsl", "Shaders/fragment_shader.glsl");

    model = float4x4::identity;
    model = model * float4x4::RotateAxisAngle(float3(1.0f, 0.0f, 0.0f), DegToRad(-55.0f));
    //float4x4 trans = model;
    view = float4x4::Translate(float3(0.0f, 0.0f, -3.0f));//App->GetEditorCamera()->GetViewMatrixTransposed();
    proj = App->GetEditorCamera()->GetProjectionMatrixTransposed();

    //LOG("%f %f %f %f \n %f %f %f %f \n %f %f %f %f \n %f %f %f %f \n", trans[0][0], trans[0][1], trans[0][2], trans[0][3], trans[1][0], trans[1][1], trans[1][2], trans[1][3], trans[2][0], trans[2][1], trans[2][2], trans[2][3], trans[3][0], trans[3][1], trans[3][2], trans[3][3]);

	return true;
}

update_status ModuleRenderExercise::PreUpdate()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Renders VBO triangle using Hello World program
    glDrawArrays(GL_TRIANGLES, 0, 3);

    return UPDATE_CONTINUE;
}

update_status ModuleRenderExercise::Update()
{
    int mvpLoc = glGetUniformLocation(shaderProgram, "mvp");
    glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, GetMVP().ptr());
    //LOG("%f %f %f %f \n %f %f %f %f \n %f %f %f %f \n %f %f %f %f \n", mvp[0][0], mvp[0][1], mvp[0][2], mvp[0][3], mvp[1][0], mvp[1][1], mvp[1][2], mvp[1][3], mvp[2][0], mvp[2][1], mvp[2][2], mvp[2][3], mvp[3][0], mvp[3][1], mvp[3][2], mvp[3][3]);

    glUseProgram(shaderProgram);

    return UPDATE_CONTINUE;
}

update_status ModuleRenderExercise::PostUpdate()
{
    return UPDATE_CONTINUE;
}

bool ModuleRenderExercise::CleanUp()
{
    return true;
}

float4x4 ModuleRenderExercise::GetMVP()
{
    mvp = proj * view * model;
    return mvp;
}
