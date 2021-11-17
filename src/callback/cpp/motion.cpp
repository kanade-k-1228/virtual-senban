#include "../hpp/motion.hpp"

void motion(const int x, const int y) {
  Global::mouse.next_path_point(x, y);
  Global::cut();
  Global::draw();
}
