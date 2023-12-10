#pragma once

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleOpenGL;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleProgram;
class ModuleRenderExercise;
class ModuleEditor;
class ModuleEditorCamera;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

    ModuleOpenGL* GetOpenGL() { return render; }
    ModuleWindow* GetWindow() { return window; }
    ModuleInput*  GetInput() { return input; }
    ModuleProgram* GetProgram() { return program; }
    ModuleRenderExercise* GetRenderExercise() { return renderExercise; }
    ModuleEditor* GetEditor() { return editor; }
    ModuleEditorCamera* GetEditorCamera() { return editorCamera; }

private:

    ModuleOpenGL* render = nullptr;
    ModuleWindow* window = nullptr;
    ModuleInput* input = nullptr;
    ModuleProgram* program = nullptr;
    ModuleRenderExercise* renderExercise = nullptr;
    ModuleEditor* editor = nullptr;
    ModuleEditorCamera* editorCamera = nullptr;

    std::list<Module*> modules;

};

extern Application* App;
