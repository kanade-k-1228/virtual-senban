#include "../hpp/bite.hpp"

void Bite::draw(Point2D<int> point) {
  glPointSize(10);
  glBegin(GL_POINTS);
  glVertex3i(point.x, point.y, 0);
  glEnd();
}
