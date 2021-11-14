#include "../hpp/initialize.hpp"

void initialize() {
  std::cout << "init" << std::endl;

  glutWarpPointer(0, 0);            // マウスカーソルを移動
  glutSetCursor(GLUT_CURSOR_NONE);  // マウスカーソル非表示
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
