#include "../hpp/Cylinder.hpp"

// 軸方向の分割数, 軸方向の分割間隔, 加工前の半径, 円の分割数
Cylinder::Cylinder(int axial_slice_number, int axial_slice_step, int initial_radius, int circular_slice_number)
    : axial_slice_number(axial_slice_number), axial_slice_step(axial_slice_step), initial_radius(initial_radius), circular_slice_number(circular_slice_number),
      circulat_slice_direction_vectors(circular_slice_number),
      radiuses(axial_slice_number, initial_radius) {
  const double angle = 2 * M_PI / circular_slice_number;
  for(int i = 0; i < circular_slice_number; ++i)
    circulat_slice_direction_vectors.at(i) = {std::cos(angle * i), std::sin(angle * i)};
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

void Cylinder::cut(Cylinderical point1, Cylinderical point2) {
  if(point1.z == point2.z) {
    int z = point1.z;
    double radius = std::min(point1.r, point2.r);
    if(z < 0 || axial_slice_number <= z) return;
    if(radiuses.at(z) > radius) radiuses.at(z) = radius;
    return;
  }

  double dydx = (point1.r - point2.r) / (point1.z - point2.z);
  Cylinderical start, end;

  if(point1.z < point2.z) {
    start = point1;
    end = point2;
  } else {
    start = point2;
    end = point1;
  }

  for(int z = start.z; z <= end.z; ++z) {
    if(z < 0 || axial_slice_number <= z) continue;
    double radius = start.r + dydx * (z - start.z);
    if(radiuses.at(z) > radius) radiuses.at(z) = radius;
  }
  return;
}

void Cylinder::reset() {
  for(int z = 0; z < radiuses.size(); ++z) radiuses.at(z) = initial_radius;
}
