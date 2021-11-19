#pragma once
#include "Space.hpp"

struct Mouse {
  Display current;
  Display prev;
  void start_path(int, int);
  void next_path_point(int, int);
};
