#include "Point.hpp"

struct Camera {
  Point3D<int> camera_position;
  Point3D<int> camera_target;
  Point3D<int> camera_posture;
  int camera_viewing_angle;
  int camera_render_min;
  int camera_render_max;
};
