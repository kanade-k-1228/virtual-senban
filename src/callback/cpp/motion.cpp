#include "../hpp/motion.hpp"

void motion(int x, int y) {
  Global::mouse.set(x, y, false);
  Global::cut();
}
