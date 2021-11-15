#include "../hpp/mouse.hpp"

void mouse(int button, int state, int x, int y) {
  std::cout << "mouse\t(" << x << "," << y << ")" << std::endl;
  // 初期マウス位置
  Global::current_mouse = {x, y};
}
