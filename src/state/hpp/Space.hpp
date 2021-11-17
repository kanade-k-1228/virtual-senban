#pragma once
#include <cmath>

struct Display {
  int x, y;
};

struct World {
  double x, y, z;
};

extern double axial_slice_step;

struct Cylinderical {
  int z;
  double r;
};

World display_to_world(Display);
Display world_to_display(World);
Cylinderical world_to_cylinderical(World);
// World cylinderical_to_world(Cylinderical);
// Display cylinderical_to_display(Cylinderical);
Cylinderical display_to_cylinderical(Display);
