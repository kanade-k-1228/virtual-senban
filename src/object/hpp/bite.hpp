#pragma once
#include <GL/glut.h>
#include <iostream>
#include <point.hpp>

class Bite {
  Point2D<int> position;

public:
  Bite();
  void draw();
};
