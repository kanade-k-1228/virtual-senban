#include "../hpp/motion.hpp"

void motion(int x, int y) {
  std::cout << "motion\t(" << x << "," << y << ")" << std::endl;

  Global::set_mouse(x, y, false);
  Global::cut();
  Global::draw();
}
