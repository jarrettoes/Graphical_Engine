
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: DirectX_Device
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: To create a device to initalize DirectX graphcis!
*
*********************************************************/

#pragma once

#ifndef DIRECTX_DEVICES_H
#define DIRECTX_DEVICES_H

#include <Private/GE_GraphicsAPI.h>
#include <iostream>
#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")



namespace GE_Graphics
{
	class GE_GRAPHICS_API DirectXDevices
	{
		public:
	
			DirectXDevices() = default;
			DirectXDevices(const DirectXDevices&) = delete;
			void operator = (const DirectXDevices&) = delete;


			DirectXDevices(const DirectXDevices&&) = delete;
			void operator = (const DirectXDevices&&) = delete;
			virtual ~DirectXDevices();


			bool Init3D_Device(HWND hDEV); //to initalize the device
			void Destory3D_Device(); //to destory the device

		private:
		
			ID3D11Device* m_device = nullptr; //the device is used to create the COM object that we need for graphics
			ID3D11DeviceContext* m_deviceContext = nullptr; //DeviceContext is for the GPU and pipeline
			IDXGISwapChain* m_swapChain = nullptr; //the swapchain is the buffers that takes turn to render the graphics
	};
}

#endif
