#pragma once
#include <cylinder.hpp>

namespace Global {
// ウィンドウ
extern Point2D<int> window;
// カメラ
extern Point3D<int> camera_position;
extern Point3D<int> camera_target;
extern Point3D<int> camera_posture;
extern int camera_viewing_angle;
extern int camera_render_min;
extern int camera_render_max;
// マウス
extern Point2D<int> current_mouse;
extern Point2D<int> prev_mouse;
// オブジェクト
extern Cylinder work;
}  // namespace Global
