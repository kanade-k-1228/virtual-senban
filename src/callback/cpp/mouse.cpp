#include "../hpp/mouse.hpp"

void mouse(const int button, const int state, const int x, const int y) {
  Global::mouse.start_path(x, y);
  if(button == GLUT_LEFT_BUTTON) {
  } else if(button == GLUT_MIDDLE_BUTTON) {
  } else if(button == GLUT_RIGHT_BUTTON) {
  }
  Global::draw();
}
