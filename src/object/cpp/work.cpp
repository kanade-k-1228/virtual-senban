#include "../hpp/work.hpp"

// 長さ, 半径, 角度の分割数
Work::Work(int length, int max_radius, int angle_resolution)
    : length_(length), max_radius_(max_radius), angle_resolution_(angle_resolution),
      angle(2 * M_PI / angle_resolution_),
      radiuses(length, max_radius),
      unit_circle_points(angle_resolution, {0.0, 0.0}) {
  for(int i = 0; i < angle_resolution_; ++i) unit_circle_points.at(i) = {std::cos(angle * i), std::sin(angle * i)};
}

void Work::draw() {
  for(int i = 0; i < radiuses.size(); ++i) {
    if(radiuses.at(i) == 0) break;  // 突っ切りの判定
    glBegin(GL_LINE_LOOP);
    for(auto point : unit_circle_points) glVertex3d(point.x * radiuses.at(i), point.y * radiuses.at(i), i);
    glEnd();
  }
}

void Work::cut(Point2D<int> point1, Point2D<int> point2) {
  std::cout << "cut\t(" << point1.x << "," << point1.y << ")~(" << point2.x << "," << point2.y << ")" << std::endl;

  if(point1.x - point2.x == 0) {
    int x = point1.x;
    int y = std::min(point1.y, point2.y);
    if(x < 0 || length_ <= x) return;
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
    if(x < 0 || length_ <= x) continue;
    double radius = start.y + dydx * (x - start.x);
    std::cout << radius << std::endl;
    if(radiuses.at(x) > radius) radiuses.at(x) = radius;
  }

  return;
}

void Work::reset() {
  for(int i = 0; i < radiuses.size(); ++i) {
    radiuses.at(i) = max_radius_;
  }
}
