
#ifndef _MODEL_C_
#define _MODEL_C_


#include "gl_utils.h"
#include "model.h"

model generate_model()
{
	int num_triangles = 2;

	float startx = -0.5;
	float starty = -0.5;
	float endx = 0.5;
	float endy = 0.5;	

	//                                     tris       3 verts xyz
	float * verts = (float *) malloc(sizeof(float) * num_triangles * 3 * 3);

	generate_quad(verts, startx, starty, endx, endy);

	model m;
	m.num_geometry = num_triangles * 3 * 3;
	m.geometry = (GLfloat *) verts;
	return m;
}

void set_vert(float * quad, float x, float y, float z)
{
	quad[0] = x;
	quad[1] = y;
	quad[2] = z;
}

void generate_quad(float * quad, float x1, float y1, float x2, float y2)
{
	set_vert(&(quad[0]), x1, y1, 0.0);
	set_vert(&(quad[0]), x1, y2, 0.0);
	set_vert(&(quad[0]), x2, y1, 0.0);

	set_vert(&(quad[0]), x2, y2, 0.0);
	set_vert(&(quad[0]), x2, y1, 0.0);
	set_vert(&(quad[0]), x1, y2, 0.0);
}

#endif