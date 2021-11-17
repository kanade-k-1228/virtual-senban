#include "../hpp/Helping.hpp"

Helping::Helping() {}

void Helping::draw(Display mouse_move_area) {
  std::cout << "helping" << std::endl;
  World max_end = display_to_world(mouse_move_area);

  glBegin(GL_POLYGON);
  glVertex3d(0, 0, 0);
  glVertex3d(max_end.x, 0, 0);
  glVertex3d(max_end.x, 0, max_end.z);
  glVertex3d(0, 0, max_end.z);
  glEnd();

  glBegin(GL_LINE);
  glVertex3d(0, 0, -100);
  glVertex3d(0, 0, 3000);
  glEnd();
}
