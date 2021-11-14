#include "../hpp/motion.hpp"

void motion(int x, int y) {
  std::cout << "motion\t(" << x << "," << y << ")" << std::endl;

  // TODO: 前回のマウス位置を記憶する
  Global::work.cut({x, y}, {x - 1, y});

  glClear(GL_COLOR_BUFFER_BIT);
  Global::work.draw();
  glFlush();
}
