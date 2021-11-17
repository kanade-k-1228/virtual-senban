#include "../hpp/motion.hpp"

void motion(int x, int y) {
  std::cout << "motion" << std::endl;
  Global::mouse.set(x, y, false);
  Global::cut();
}
