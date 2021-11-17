#include "../hpp/passive_motion.hpp"

void passive_motion(int x, int y) {
  std::cout << "passive\t(" << x << "," << y << ")" << std::endl;
  Global::set_mouse(x, y, false);
}
