#include "../hpp/mouse_mapping.hpp"

void mouse_mapping(int* x, int* y) {
  *x = 2 * (*x) - glutGet(GLUT_WINDOW_WIDTH);
  *y = -2 * (*y) + glutGet(GLUT_WINDOW_HEIGHT);
}
