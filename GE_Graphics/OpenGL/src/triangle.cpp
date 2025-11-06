#include "triangle.h"
#include "GE_EngineCoreUtilites.h"


//=====================================================================================================================================================================================================
// setup the vertices for the triangle
//=====================================================================================================================================================================================================
void GE_GRAPHICS::triangle_test::setup_triangle()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices_arr), _vertices_arr, GL_STATIC_DRAW);

}
