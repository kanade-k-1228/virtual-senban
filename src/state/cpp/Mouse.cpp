#include "../hpp/Mouse.hpp"

void Mouse::set_mouse(int x, int y, bool is_first) {
  prev_mouse = (is_first ? (Window){x, y} : current_mouse);
  current_mouse = {x, y};
}
