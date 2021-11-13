#pragma once
#include "point.hpp"
#include <GL/glut.h>

void mouse_mapping(int*, int*);
Point2D<double> mouse_to_2D(int, int);
