
#ifndef _GL_UTILS_H_
#define _GL_UTILS_H_

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "gl_utils.h"

#include <GL/gl.h>
#include <gmtl/gmtl.h>

using namespace gmtl;

struct model
{
	GLfloat * geometry;
	unsigned int num_geometry;
};
struct gl_model
{
	GLuint geometry_buffer;
	unsigned int num_geometry;
};

gl_model create_buffer(model & m);
void draw(gl_model & glm);


#endif