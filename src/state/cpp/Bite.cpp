#include "../hpp/Bite.hpp"

void Bite::draw(Point3D<int> point) {
  glPointSize(10);
  glBegin(GL_POINTS);
  glVertex3i(point.x, point.y, point.z);
  glEnd();
}
