#include "../hpp/bite.hpp"

Bite::Bite() : position({1, 1}) {}

void Bite::draw() {
  glutSolidSphere(10, 10, 10);
  // glBegin(GL_LINE_LOOP);
  // glEnd();
}
