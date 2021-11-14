#include "../hpp/cylinder.hpp"

// 軸方向の分割数, 軸方向の分割間隔, 加工前の半径, 円の分割数
Cylinder::Cylinder(int axial_slice_number, int axial_slice_step, int initial_radius, int circular_slice_number)
    : axial_slice_number(axial_slice_number), axial_slice_step(axial_slice_step), initial_radius(initial_radius), circular_slice_number(circular_slice_number),
      circulat_slice_direction_vectors(circular_slice_number),
      radiuses(axial_slice_number, initial_radius) {
  const double angle = 2 * M_PI / circular_slice_number;
  for(int i = 0; i < circular_slice_number; ++i) circulat_slice_direction_vectors.at(i) = {std::cos(angle * i), std::sin(angle * i)};
}

void Cylinder::draw() {
  for(int i = 0; i < radiuses.size(); ++i) {
    if(radiuses.at(i) == 0) break;  // 切り落とされた
    // 円盤の描画
    glBegin(GL_LINE_LOOP);
    for(auto point : circulat_slice_direction_vectors) glVertex3d(point.x * radiuses.at(i), point.y * radiuses.at(i), axial_slice_step * i);
    glEnd();
  }
}

void Cylinder::cut(Point2D<int> point1, Point2D<int> point2) {
  std::cout << "cut\t(" << point1.x << "," << point1.y << ")~(" << point2.x << "," << point2.y << ")" << std::endl;
  point1.x /= axial_slice_step;
  point2.x /= axial_slice_step;

  if(point1.x - point2.x == 0) {
    int x = point1.x;
    int y = std::min(point1.y, point2.y);
    if(x < 0 || axial_slice_number <= x) return;
    if(radiuses.at(x) > y) radiuses.at(x) = y;
    return;
  }

  double dydx = (double)(point1.y - point2.y) / (point1.x - point2.x);
  Point2D<int> start, end;

  if(point1.x < point2.x) {
    start = point1;
    end = point2;
  } else {
    start = point2;
    end = point1;
  }

  for(int x = start.x; x <= end.x; ++x) {
    if(x < 0 || axial_slice_number <= x) continue;
    double radius = start.y + dydx * (x - start.x);
    std::cout << radius << std::endl;
    if(radiuses.at(x) > radius) radiuses.at(x) = radius;
  }

  return;
}

void Cylinder::reset() {
  for(int i = 0; i < radiuses.size(); ++i) radiuses.at(i) = initial_radius;
}
