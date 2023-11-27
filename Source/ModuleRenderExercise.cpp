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
    //Triangle definition
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    shaderProgram = App->GetProgram()->CreateProgram("../Source/Shaders/triangle.vs", "./../Source/Shaders/triangle.fs");

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);

	return true;
}

update_status ModuleRenderExercise::PreUpdate()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw our first triangle
    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glBindVertexArray(0); // no need to unbind it every time 

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
