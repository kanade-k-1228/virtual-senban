#pragma once
#include "bite.hpp"
#include "cylinder.hpp"

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
void set_mouse(int, int, bool);

// 円柱ワーク
extern Cylinder work;
void cut();

// バイト
extern Bite bite;

// 描画関数
void draw();
// 初期化関数
void init();
}  // namespace Global
