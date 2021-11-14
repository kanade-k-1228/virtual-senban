#pragma once
#include <cylinder.hpp>

namespace Global {
extern Cylinder work;
extern Point2D<int> window;
extern Point2D<int> current_mouse;
extern Point2D<int> prev_mouse;

// カメラ
extern Point3D<int> camera_position;  // 位置
extern Point3D<int> camera_target;    // 注視点
extern Point3D<int> camera_posture;   // 姿勢
extern int camera_viewing_angle;      // 視野角
extern int camera_render_min;         // 最小描画距離
extern int camera_render_max;         // 最大描画距離
}  // namespace Global
