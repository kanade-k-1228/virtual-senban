#include "../hpp/display.hpp"

void display() {
  std::cout << "display" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT);
  Global::work.draw();
  glFlush();
}
