#include "../include/Game.hpp"

void Bite::draw(Space::World point) {
  glPointSize(10);
  glBegin(GL_POINTS);
  glVertex3i(point.x, point.y, point.z);
  glEnd();
}
