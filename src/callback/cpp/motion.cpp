#include "../hpp/motion.hpp"

void motion(int x, int y) {
  mouse_mapping(&x, &y);
  std::cout << "motion\t(" << x << "," << y << ")" << std::endl;
}
