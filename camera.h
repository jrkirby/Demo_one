
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <GL/gl.h>
#include <gmtl/gmtl.h>
using namespace gmtl;


struct camera
{
	Matrix44f tf;
	float radius;
	float height;
	float speed;
	float angle;
};

void generate_camera(camera * cam, float radius, float height, float speed);
void update_camera(camera * cam);
void view(camera * cam);
void clean_cam(camera * cam);

#endif