#include "../hpp/mouse.hpp"

void mouse(int button, int state, int x, int y) {
  mouse_mapping(&x, &y);
  std::cout << "mouse\t(" << x << "," << y << ")" << std::endl;
}
