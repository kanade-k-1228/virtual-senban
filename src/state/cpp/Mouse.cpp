#include "../hpp/Mouse.hpp"

void Mouse::set(int x, int y, bool is_first) {
  prev = (is_first ? (Display){x, y} : current);
  current = {x, y};
}
