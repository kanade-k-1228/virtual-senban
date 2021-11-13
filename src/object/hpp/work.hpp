#pragma once
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include <point.hpp>
#include <vector>

class Work {
  // 形状情報
  int length_;                   // 丸棒の長さ
  int max_radius_;               // 丸棒の半径
  std::vector<double> radiuses;  // 外形

  // 描画情報
  int angle_resolution_;                            // 円の分割数
  double angle;                                     // 円の分割角度
  std::vector<Point2D<double>> unit_circle_points;  // 単位円の分割点

public:
  Work(int, int, int);
  void draw();
  void cut(Point2D<int>, Point2D<int>);
  void reset();
};
