#include "../hpp/motion.hpp"

void motion(int x, int y) {
  std::cout << "motion\t(" << x << "," << y << ")" << std::endl;

  // TODO: FIX 初回のマウス位置を変更
  Global::prev_mouse = Global::current_mouse;
  Global::current_mouse = {x, y};

  Global::work.cut(Global::prev_mouse, Global::current_mouse);

  glClear(GL_COLOR_BUFFER_BIT);
  Global::work.draw();
  glFlush();
}
