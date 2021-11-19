#include "../include/Space.hpp"

double axial_slice_step = 10;

World display_to_world(Display display) {
  return (World){(double)(-display.y), 0, (double)(display.x)};
}

Display world_to_display(World world) {
  return {std::floor(world.z), std::floor(-world.x)};
}

Cylinderical world_to_cylinderical(World world) {
  return {std::floor(world.z / axial_slice_step), std::sqrt(world.x * world.x + world.y * world.y)};
}

World cylinderical_to_world(Cylinderical cylinderical) {
  return {-cylinderical.r, 0, cylinderical.z * axial_slice_step};
}
// Display cylinderical_to_display(Cylinderical) {}

Cylinderical display_to_cylinderical(Display display) {
  return {std::floor(display.x / axial_slice_step), display.y};
}
