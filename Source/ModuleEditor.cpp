#include "ModuleEditor.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleOpenGL.h"
#include "imgui-1.90/backends/imgui_impl_sdl2.h"
#include "imgui-1.90/backends/imgui_impl_opengl3.h"

ModuleEditor::ModuleEditor()
{
}

ModuleEditor::~ModuleEditor()
{
}

bool ModuleEditor::Init()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(App->GetWindow()->window, App->GetOpenGL()->GetContext());
    ImGui_ImplOpenGL3_Init();

	return true;
}

update_status ModuleEditor::PreUpdate()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    return UPDATE_CONTINUE;
}

update_status ModuleEditor::Update()
{
    ShowLogWindow();
    ShowMainMenuBar();

    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return UPDATE_CONTINUE;
}

bool ModuleEditor::CleanUp()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    return true;
}

void ModuleEditor::AddLog(const char* text)
{
    logWindow.AddLog(text);
}

void ModuleEditor::ShowLogWindow()
{
    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
    ImGui::Begin("Console");
    ImGui::End();

    // Actually call in the regular Log helper (which will Begin() into the same window as we just did)
    logWindow.Draw("Console");
}

void ModuleEditor::ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("GitHub page")) {}
            if (ImGui::MenuItem("About")) {}
            if (ImGui::MenuItem("Quit")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}