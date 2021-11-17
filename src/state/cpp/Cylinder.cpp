#include "../hpp/Cylinder.hpp"

// 軸方向の分割数, 軸方向の分割間隔, 加工前の半径, 円の分割数
Cylinder::Cylinder(int axial_slice_number, int axial_slice_step, int initial_radius, int circular_slice_number)
    : axial_slice_number(axial_slice_number), axial_slice_step(axial_slice_step), initial_radius(initial_radius), circular_slice_number(circular_slice_number),
      circular_slice_direction_vectors(circular_slice_number),
      radiuses(axial_slice_number, initial_radius) {
  const double angle = 2 * M_PI / circular_slice_number;
  for(int i = 0; i < circular_slice_number; ++i)
    circular_slice_direction_vectors.at(i) = {std::cos(angle * i), std::sin(angle * i)};
}

void Cylinder::draw() {
  for(int i = 0; i < radiuses.size(); ++i) {
    // TODO FIX 切断がうまくいかない
    // if(radiuses.at(i) == 0) break;  // 切り落とされた
    // 円盤の描画
    glBegin(GL_LINE_LOOP);
    for(auto point : circular_slice_direction_vectors)
      glVertex3d(point.x * radiuses.at(i), point.y * radiuses.at(i), axial_slice_step * i);
    glEnd();
  }
  for(auto point : circular_slice_direction_vectors) {
    glBegin(GL_LINE);
    glVertex3d(0, 0, 0);
    for(int i = 0; i < radiuses.size(); ++i)
      glVertex3d(point.x * radiuses.at(i), point.y * radiuses.at(i), axial_slice_step * i);
    glVertex3d(0, 0, cylinderical_to_world({axial_slice_number, 0}).z);
    glEnd();
  }
}

void Cylinder::cut_point(Cylinderical point) {
  if(point.z < 0 || axial_slice_number <= point.z) return;
  if(radiuses.at(point.z) > point.r) radiuses.at(point.z) = point.r;
}

void Cylinder::add_point(Cylinderical point) {
  if(point.z < 0 || axial_slice_number <= point.z) return;
  if(radiuses.at(point.z) < point.r) radiuses.at(point.z) = point.r;
}

void Cylinder::cut_path(Cylinderical point1, Cylinderical point2) {
  if(point1.z == point2.z) {
    cut_point(point1);
    cut_point(point2);
    return;
  }
  double dydx = (point1.r - point2.r) / (point1.z - point2.z);
  Cylinderical start = (point1.z < point2.z ? point1 : point2);
  Cylinderical end = (point1.z < point2.z ? point2 : point1);
  for(int z = start.z; z <= end.z; ++z) {
    cut_point({z, start.r + dydx * (z - start.z)});
  }
}

void Cylinder::add_path(Cylinderical point1, Cylinderical point2) {
  if(point1.z == point2.z) {
    add_point(point1);
    add_point(point2);
    return;
  }
  double dydx = (point1.r - point2.r) / (point1.z - point2.z);
  Cylinderical start = (point1.z < point2.z ? point1 : point2);
  Cylinderical end = (point1.z < point2.z ? point2 : point1);
  for(int z = start.z; z <= end.z; ++z) {
    add_point({z, start.r + dydx * (z - start.z)});
  }
}

void Cylinder::reset() {
  for(int z = 0; z < radiuses.size(); ++z) radiuses.at(z) = initial_radius;
}
