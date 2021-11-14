#include "../hpp/keyboard.hpp"

void keyboard(const unsigned char key, const int x, const int y) {
  std::cout << "key\t" << key << std::endl;
  if(key == ' ') {
    Global::work.reset();
    glClear(GL_COLOR_BUFFER_BIT);
    Global::work.draw();
    glFlush();
  }
}
