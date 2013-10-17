
#ifndef _MODEL_H_
#define _MODEL_H_

#include "gl_utils.h"

//we need some a quad (18 floats) space allocated, we fill it up with one quad
void generate_quad(float * quad, float x1, float y1, float x2, float y2);
//similarly, vert must be avaliable space which gets set;
void set_vert(float * vert, float x, float y, float z);
model generate_model();

#endif