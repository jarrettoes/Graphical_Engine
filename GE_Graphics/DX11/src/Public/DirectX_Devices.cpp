#include "Private/DirectX_Devices.h"
#include <iostream>

bool GE_Graphics::DirectXDevices::Init3D_Device(HWND hDEV)
{

	if (hDEV == nullptr)
	{
		std::cout << "no suitable Window handle!" << std::endl;
		return false;
	}

	DXGI_SWAP_CHAIN_DESC swap_desc; //the swap chain desicription is a struct similar to WNDCLASS!

	ZeroMemory(&swap_desc, sizeof(swap_desc)); //sets swap_desc struct to null!

	swap_desc.BufferCount = 3; //for how many back buffers we need so i'll choose 3 for now because its a game enigne and we need more buffer counts
	swap_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //32-bit color!
	swap_desc.OutputWindow = hDEV; //this is the window handle so we'll have to plug this into the window.h code in GE_EngineCore!
	swap_desc.Windowed = true;
	swap_desc.SampleDesc.Count = 4; //used for anti-aliasing
	swap_desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	
	D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, D3D_FEATURE_LEVEL_11_0, 
								  D3D11_SDK_VERSION, &swap_desc, &m_swapChain, &m_device, nullptr, &m_deviceContext);
	

	return true;
}

void GE_Graphics::DirectXDevices::Destory3D_Device()
{
	m_swapChain->Release();
	m_device->Release();
	m_deviceContext->Release();
}

GE_Graphics::DirectXDevices::~DirectXDevices()
{
	Destory3D_Device();
}