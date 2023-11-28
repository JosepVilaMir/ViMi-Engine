#include "ModuleRenderExercise.h"
#include "Application.h"
#include <GL/glew.h>
#include <iostream>
#include "ModuleWindow.h"
#include "ModuleProgram.h"
#include "SDL.h"

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
    -1, -1, 0,
     1, -1, 0,
     0,  1, 0
    };

    // Loads a triangle into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Creates a program with Hello World vertex and fragment shaders
    shaderProgram = App->GetProgram()->CreateProgram("../Source/Shaders/triangle.vs", "./../Source/Shaders/triangle.fs");

    glUseProgram(shaderProgram);

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
    return UPDATE_CONTINUE;
}

update_status ModuleRenderExercise::PostUpdate()
{
    SDL_GL_SwapWindow(App->GetWindow()->window);
    return UPDATE_CONTINUE;
}

bool ModuleRenderExercise::CleanUp()
{
    return true;
}
