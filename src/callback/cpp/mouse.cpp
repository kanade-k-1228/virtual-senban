#include "../hpp/mouse.hpp"

void mouse(int button, int state, int x, int y) {
  std::cout << "mouse\t(" << x << "," << y << ")" << std::endl;
  Global::set_mouse(x, y, true);
}
