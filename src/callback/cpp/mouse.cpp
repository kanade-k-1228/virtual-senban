#include "../hpp/mouse.hpp"

void mouse(int button, int state, int x, int y) {
  Global::mouse.set(x, y, true);
}
