#pragma once

struct Window {
  int x, y;
};

struct World {
  double x, y, z;
};

struct Cylinderical {
  int z;
  double r;
};

World window_to_world(Window);
Window world_to_window(World);
Cylinderical world_to_cylinderical(World);
Window cylinderical_to_window(Cylinderical);


Cylinderical window_to_cylinderical(Window);
