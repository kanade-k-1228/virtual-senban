#include "../hpp/Cylinder.hpp"

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
    // TODO FIX 切断がうまくいかない
    // if(radiuses.at(i) == 0) break;  // 切り落とされた
    // 円盤の描画
    glBegin(GL_LINE_LOOP);
    for(auto point : circulat_slice_direction_vectors)
      glVertex3d(point.x * radiuses.at(i), point.y * radiuses.at(i), axial_slice_step * i);
    glEnd();
  }
}

void Cylinder::cut(Point3D<int> point1, Point3D<int> point2) {
  int index1 = point1.z / axial_slice_step;
  int index2 = point2.z / axial_slice_step;
  double radius1 = sqrt(point1.x * point1.x + point1.y * point1.y);
  double radius2 = sqrt(point2.x * point2.x + point2.y * point2.y);

  if(index1 == index2) {
    int index = index1;
    double radius = std::min(radius1, radius2);
    if(index < 0 || axial_slice_number <= index) return;
    if(radiuses.at(index) > radius) radiuses.at(index) = radius;
    return;
  }

  double dydx = (radius1 - radius2) / (index1 - index2);
  int index_start, index_end;
  double radius_start, radius_end;
  Point2D<int> start, end;
  if(index1 < index2) {
    index_start = index1;
    index_end = index2;
    radius_start = radius1;
    radius_end = radius2;
  } else {
    index_start = index2;
    index_end = index1;
    radius_start = radius2;
    radius_end = radius1;
  }

  for(int i = index_start; i <= index_end; ++i) {
    if(i < 0 || axial_slice_number <= i) continue;
    double radius = radius_start + dydx * (i - index_start);
    if(radiuses.at(i) > radius) radiuses.at(i) = radius;
  }
  return;
}

void Cylinder::reset() {
  for(int i = 0; i < radiuses.size(); ++i) radiuses.at(i) = initial_radius;
}
