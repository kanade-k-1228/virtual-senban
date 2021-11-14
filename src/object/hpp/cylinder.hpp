#pragma once
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include <point.hpp>
#include <vector>

class Cylinder {
  int axial_slice_number;                                         // 軸方向の分割数 [slice]
  int axial_slice_step;                                           // 軸方向の分割間隔 [len/slice]
  int initial_radius;                                             // 加工前の半径 [len]
  int circular_slice_number;                                      // 円の分割数
  std::vector<Point2D<double>> circulat_slice_direction_vectors;  // 単位円の分割点 [cos(2pi/i),sin(2pi/i)]
  std::vector<double> radiuses;                                   // 半径配列

public:
  Cylinder(int, int, int, int);
  void draw();
  void cut(Point2D<int>, Point2D<int>);
  void reset();
};
