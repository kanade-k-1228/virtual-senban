#pragma once
#include "Space.hpp"

struct Mouse {
  Window current;
  Window prev;
  void set(int, int, bool);
};
