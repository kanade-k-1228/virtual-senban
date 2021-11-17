#pragma once
#include "Space.hpp"

struct Mouse {
  Display current;
  Display prev;
  void set(int, int, bool);
};
