#include "../hpp/passive_motion.hpp"

void passive_motion(int x, int y) {
  // mouse_mapping(&x, &y);
  std::cout << "passive\t(" << x << "," << y << ")" << std::endl;


  Instance::work.cut({x, y}, {x - 1, y - 1});

  glClear(GL_COLOR_BUFFER_BIT);
  Instance::work.draw();
  glFlush();
}
