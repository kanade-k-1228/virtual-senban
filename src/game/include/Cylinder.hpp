#pragma once
#include "Space.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

class Cylinder {
  int axial_slice_number;                               // 軸方向の分割数 [slice]
  int axial_slice_step;                                 // 軸方向の分割間隔 [len/slice]
  int initial_radius;                                   // 加工前の半径 [len]
  int circular_slice_number;                            // 円の分割数
  std::vector<World> circular_slice_direction_vectors;  // 単位円の分割点 [cos(2pi/i),sin(2pi/i)]
  std::vector<double> radiuses;                         // 半径配列

public:
  Cylinder(int, int, int, int);
  enum ReshapeDirection { CUT,
                          ADD };
  void draw();
  void cut_point(Cylinderical);
  void add_point(Cylinderical);
  void cut_path(Cylinderical, Cylinderical);
  void add_path(Cylinderical, Cylinderical);
  void reshape(Cylinderical, Cylinderical, ReshapeDirection);
  void reset();
};
