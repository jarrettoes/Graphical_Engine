#include "include/DirectX_Devices.h"
#include <iostream>



GE_Graphics::DirectXDevices::~DirectXDevices()
{
	Destory3D_Device();
}

bool GE_Graphics::DirectXDevices::Init3D_Device(HWND hDEV)
{
	DXGI_SWAP_CHAIN_DESC swap_desc; //the swap chain desicription is a struct similar to WNDCLASS!

	ZeroMemory(&swap_desc, sizeof(swap_desc)); //sets swap_desc struct to null!

	swap_desc.BufferCount = 3; //for how many back buffers we need so i'll choose 3 for now because its a game enigne and we need more buffer counts
	swap_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //32-bit color!
	swap_desc.OutputWindow = hDEV; //this is the window handle so we'll have to plug this into the window.h code in GE_EngineCore!
	swap_desc.Windowed = true
	
	return false;
}

void GE_Graphics::DirectXDevices::Destory3D_Device()
{
}
