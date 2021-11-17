#include "../hpp/Bite.hpp"

void Bite::draw(World point) {
  glPointSize(10);
  glBegin(GL_POINTS);
  glVertex3i(point.x, point.y, point.z);
  glEnd();
}
