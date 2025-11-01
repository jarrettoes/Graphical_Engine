#include "imgui_test.h"
#include "GE_CoreUtilites.h"
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_win32.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

void GE_ENGINE_CORE::imgui_engine::imgui_init(HWND hwnd)
{
	//refering to the ImGui GetStarted page on their github
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	
	//flags to enable docking, keyboards, etc
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	if (!hwnd)
	{
		__GE_ENGINE_ERROR_LOG("no suitable window handle (hwnd) was found");
		return;
	}
	__GE_ENGINE_SUCESS_LOG("got a suitable hwnd!");

	//we need to get a window handle for imgui if we're using win32 API
	ImGui_ImplWin32_Init(hwnd);
	if (!ImGui_ImplOpenGL3_Init("#version 330"))
	{
		__GE_ENGINE_ERROR_LOG("Initalizing openGL for imGui failed");
		return;
	}
	__GE_ENGINE_SUCESS_LOG("openGL for imGui is initalized");


	__GE_ENGINE_INFO_LOG("imgui is initalized!");
}

void GE_ENGINE_CORE::imgui_engine::imgui_start()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
}

void GE_ENGINE_CORE::imgui_engine::imgui_end()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GE_ENGINE_CORE::imgui_engine::imgui_clean()
{
	__GE_ENGINE_INFO_LOG("imgui is shutting down");
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

LRESULT GE_ENGINE_CORE::imgui_proc_handle_wrapper(HWND _hwnd, UINT _uint, WPARAM _wparam, LPARAM _lparam)
{
	if(ImGui_ImplWin32_WndProcHandler(_hwnd, _uint, _wparam, _lparam))
		return 1;

	return 0;
}
