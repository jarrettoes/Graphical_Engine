#pragma once


#include "GE_Graphics.h"
#include <iostream>
#include <glad/glad.h>


namespace GE_GRAPHICS
{
	class GE_GRAPHICS_API triangle_test
	{
		public:

			void setup_triangle();

		protected:

		private:

			unsigned int VBO; //the vertex buffer object used for the triangle
			
			//the triangles vertices are going to be respresented via a flaot vertex
			float _vertices_arr[3] = { (-0.5f, -0.5f, 0.0f ),  //x axis
									 ( 0.5f, -0.5f, 0.0f ),  //y axis
								     ( 0.0f,  0.5f, 0.0f ),  //z axis
								  };

	};
}