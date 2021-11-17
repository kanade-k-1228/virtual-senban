#include "../hpp/Mouse.hpp"

void Mouse::start_path(int x, int y) {
  prev = {x, y};
  current = {x, y};
}

void Mouse::next_path_point(int x, int y) {
  prev = current;
  current = {x, y};
}
