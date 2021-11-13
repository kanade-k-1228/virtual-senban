#pragma once

struct Point {
  int x, y;
};

template <typename T>
struct Point2D {
  T x, y;
};

template <typename T>
struct Point3D {
  T x, y, z;
};
