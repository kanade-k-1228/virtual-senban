#include "../include/Helping.hpp"

Helping::Helping() {}

void Helping::draw(Display mouse_move_area) {
  World max_end = display_to_world(mouse_move_area);

  // glBegin(GL_LINE_LOOP);
  // glVertex3d(0, 0, 0);
  // glVertex3d(max_end.x, 0, 0);
  // glVertex3d(max_end.x, 0, max_end.z);
  // glVertex3d(0, 0, max_end.z);
  // glEnd();

  glLineWidth(10);
  glBegin(GL_LINE_LOOP);
  glVertex3d(0, 0, -3000);
  glVertex3d(0, 0, 3000);
  glEnd();
  glLineWidth(1);
}
