
#ifndef _GL_UTILS_C_
#define _GL_UTILS_C_

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "gl_utils.h"

#include <GL/gl.h>
#include <gmtl/gmtl.h>

using namespace gmtl;


gl_model create_buffer(model & m)
{
	gl_model glm;

	glm.num_geometry = m.num_geometry;

	glGenBuffersARB(1, &(glm.geometry_buffer));
	glBindBuffer(GL_ARRAY_BUFFER, glm.geometry_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 8 * m.num_geometry, m.geometry, GL_STATIC_DRAW);

	return glm;
}

void draw(gl_model & glm)
{
	//Update Model Matrix

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
//	glMultMatrixf( myMat.getData() );

	//Render
	// Step 1
	glBindBuffer(GL_ARRAY_BUFFER, glm.geometry_buffer);

	// Step 2
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	// Step 3
	glTexCoordPointer(3, GL_FLOAT, sizeof(GLfloat)*8, (GLvoid *)(sizeof(GLfloat)*5));
	glNormalPointer(GL_FLOAT, sizeof(GLfloat)*8, (GLvoid *)(sizeof(GLfloat)*3));
	glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*8, NULL);

	// Step 4
	glDrawArrays(GL_TRIANGLES, 0, glm.num_geometry);

	// Step 5
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();
}


#endif