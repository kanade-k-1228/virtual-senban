#include "../hpp/keyboard.hpp"

void keyboard(const unsigned char key, const int x, const int y) {
  std::cout << "key\t" << key << std::endl;
  if(key == ' ') {
    Instance::work.reset();
    glClear(GL_COLOR_BUFFER_BIT);
    Instance::work.draw();
    glFlush();
  }
}
