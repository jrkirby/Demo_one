
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1


#include <GL/glut.h>
#include <GL/gl.h>
#include <gmtl/gmtl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#include "camera.h"

using namespace std;

struct controller	
{
	int frame;
	camera * cam;
	double last_T;

};

controller cont;

static double ftime(void) {
	struct timeval t;
	gettimeofday(&t, NULL);

	return 1.0*t.tv_sec + 1e-6*t.tv_usec;
}

void animate();

/*
* Animate every 60th of a second
*/
void idle(void) {
	double now_T = ftime();
	double delta_T = now_T - cont.last_T;
	if(delta_T >= (1.0 / 60.0))	//time since last frame is more than 60th of a second
	{
		cont.last_T = now_T;
		animate();
	}

}


void animate()
{

	update_camera(cont.cam);

	glutPostRedisplay();
}

/*
* Execute everything that will happen in one frame
*/
void display()
{
	//update game objects

	//draw game objects
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	view(cont.cam);
//	draw(cont.c);

	glFlush();
}

/*
* initialize every data structure
* setup openGL and window
* prepare for game execution
*/
void init()
{

	//init openGL
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");
	glutIdleFunc(idle);
	glutPostRedisplay();
	glutDisplayFunc(display);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(45, 1, .01, 1000);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	cont.cam = (camera *) malloc(sizeof(camera));
	generate_camera(cont.cam, 4, 1, 0.01);

	glutMainLoop();

}


/*
* clean up any variables/memory
*/
void exit();

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	init();
}
