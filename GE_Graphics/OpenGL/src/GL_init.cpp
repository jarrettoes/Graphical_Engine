#include "GL_init.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GE_CoreUtilites.h"

int GE_GRAPHICS::gl_init::init_window(HWND hwnd)
{
	gl_hdc = GetDC(hwnd); //we start off by getting the device context
	
	PIXELFORMATDESCRIPTOR pfd {}; //we need to setup our pixel descriptoers for the context
	//we wnat the exact size of the data structure so just teh size of pfd.
	pfd.nSize = sizeof(pfd);
	//what version the data structure should be. documentation said to just set it to 1.
	pfd.nVersion = 1;
	/*for this part we need the three buffers : PFD_DRAW_TO_WINDOW because we're drawing onto our own window instead of creating one from glfw,
	  PFD_SUPPORT_OPENGL because we're using openGl graphics, and PFD_DOUBLEBUFFER bcause what we're doing is that we're setting up two buffers
	  to communicate with each other via our windows API window and opengl*/
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	//for the PFD_TYPE_RGBA we're essentially saying this is the main spectrum for all pixels red (R), green (G), blue (B), alpha (a) alpha is more of transparency however
	pfd.iPixelType = PFD_TYPE_RGBA;
	//we're doing 32 because (R)ed = 8, (G)reen = 8, (B)lue = 8, (A)lpha = 8 in total is 32 bits!
	pfd.cColorBits = 32;
	//as for depth we're getting the depth of the depth z-axis buffer (how ever windows stated) so we would only need just Red, Green and Blue
	pfd.cDepthBits = 24;
	//as for iLayerType apperntly this is legacy. GPUs now only really use one layer which ish teh main plane so well just use that but again iLayerType is not really needed
	pfd.iLayerType = PFD_MAIN_PLANE;

	//now we need to setup our pixelformat via the choosePixelFormat function
	int pixel_format = ChoosePixelFormat(gl_hdc, &pfd);
	//now we use the SetPixelFormat function;
	SetPixelFormat(gl_hdc, pixel_format, &pfd);

	//now create the openGl device context 
	openGl_context = wglCreateContext(gl_hdc);
	wglMakeCurrent(gl_hdc, openGl_context);

	//now setup glad initalization
	if (!gladLoadGLLoader((GLADloadproc)wglGetProcAddress))
	{
		__GE_ENGINE_ERROR_LOG("glad failed to initalize!");
		return EXIT_FAILURE;
	}
	__GE_ENGINE_SUCESS_LOG("gald is succssfully initalized!");


	__GE_ENGINE_INFO_LOG("hello from openGL!");

	return EXIT_SUCCESS;
}

void GE_GRAPHICS::gl_init::gl_render()
{
	//according to the learn openGL tutorial!
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//refer back to the pixel format descriptor! and how we set teh cDepthBits to 24 that flag GL_DEPHT_BUFFER_BITS is correspodant to that!
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	wglMakeCurrent(gl_hdc, openGl_context); //have to keep making our device and context current
}

void GE_GRAPHICS::gl_init::swap_buffers(HDC device_buff)
{
	//we need to sawp the buffers so that the rendering can be displayed to the main window
	SwapBuffers(device_buff);
}

void GE_GRAPHICS::gl_init::gl_quit()
{
	//we can just delete our devices and contexts when we quit
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(openGl_context);
	__GE_ENGINE_INFO_LOG("gl_quit is called!");
}


GE_GRAPHICS::gl_init::~gl_init()
{
	gl_quit();
}
