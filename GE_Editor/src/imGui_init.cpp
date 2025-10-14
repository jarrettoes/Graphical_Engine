#include "imGui_init.h"
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_win32.h>

void GE_EDITOR::imGui_init::init(HWND hwnd)
{
	if (!hwnd)
	{
		__GE_ENGINE_ERROR_LOG("imGui couldn't be intialized because of a null window handle");
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext(); //we must create a context of imGui
	ImGuiIO& io = ImGui::GetIO();

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	//having issues with calling in ImGuiConfigFlags_DockingEnable
	//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

	//we must implement the handle for our win32 window and for openGl 
	ImGui_ImplWin32_Init(hwnd); 
	ImGui_ImplOpenGL3_Init("#version 460");

	__GE_ENGINE_SUCESS_LOG("imGui is successfully initalized!");
}

void GE_EDITOR::imGui_init::imGui_update_start()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	
	ImGui::Begin("Window");
	ImGui::Text("Hello World");
	ImGui::End();
}

void GE_EDITOR::imGui_init::imGui_uddate_end()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GE_EDITOR::imGui_init::imGui_shutdown()
{
	__GE_ENGINE_INFO_LOG("imGui is shutting down");

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

GE_EDITOR::imGui_init::~imGui_init()
{
	//that that shi down
	imGui_shutdown();
}
