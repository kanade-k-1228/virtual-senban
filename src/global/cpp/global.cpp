#include "../hpp/global.hpp"

Cylinder Global::work = Cylinder(190, 10, 1080, 30);
Point2D<int> Global::window = {1920, 1080};
Point2D<int> Global::current_mouse = {0, 0};
Point2D<int> Global::prev_mouse = {0, 0};


// カメラ
Point3D<int> Global::camera_position = {-5000, 0, 3000};  // 位置
Point3D<int> Global::camera_target = {0, 0, 1000};        // 注視点
Point3D<int> Global::camera_posture = {0, 1, 0};          // 姿勢
int Global::camera_viewing_angle = 30;                    // 視野角
int Global::camera_render_min = 1;                        // 最小描画距離
int Global::camera_render_max = 8000;                     // 最大描画距離
