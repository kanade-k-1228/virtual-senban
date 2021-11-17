#include "../hpp/passive_motion.hpp"

void passive_motion(const int x, const int y) {
  Global::mouse.next_path_point(x, y);
  Global::draw();
}
