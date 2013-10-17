
#ifndef _CAMERA_C_
#define _CAMERA_C_

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <gmtl/gmtl.h>
#include <stdio.h>
#include <GL/glut.h>

#include "camera.h"
using namespace gmtl;




/*
* gets initial position / orientation
*/
void generate_camera(camera * cam, float radius, float height, float speed)
{
	printf("generating camera\n");
	cam->radius = radius;
	cam->angle = 0;
	cam->height = height;
	cam->speed = speed;
	update_camera(cam);
}

/*
* updates camera position and orientation
* using new/old car data
*/
void update_camera(camera * cam)
{
	Vec3f position = Vec3f(cam->radius * Math::cos(cam->angle), cam->radius * Math::cos(cam->angle), cam->height);
	cam->tf = makeTrans<Matrix44f>(position);
	cam->angle += cam->speed;
}


/*
* updates openGL view matrix
*/
void view(camera * cam)
{
	glMatrixMode(GL_MODELVIEW);
	//camera translations are opposite of model translations
//	Vec3f trans = makeTrans<Vec3f>(cam->tf);
/*	gluLookAt(
			1.0, 1.0, 1.0,
			0, 0, 0,
			0.0, 0.0, 1.0
			);*/
	glTranslatef( 0.0, 0.0, -1.0);
}

/*
* deletes camera
*/
void clean_cam(camera * cam);


#endif