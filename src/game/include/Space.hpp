#pragma once
#include <cmath>

namespace Space {
struct Display {
  int x, y;
};

struct World {
  double x, y, z;
};

struct Cylinderical {
  int z;
  double r;
  const double z_step;
};

World display_to_world(Display);
Display world_to_display(World);
Cylinderical world_to_cylinderical(World);
World cylinderical_to_world(Cylinderical);
// Display cylinderical_to_display(Cylinderical);
Cylinderical display_to_cylinderical(Display);
}  // namespace Space
