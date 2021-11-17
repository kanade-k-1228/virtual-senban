#include "../hpp/Global.hpp"

// ウィンドウ
Point2D<int> Global::window = {1920, 1080};

// カメラ
Point3D<int> Global::camera_position = {-5000, 1000, 3000};  // 位置
Point3D<int> Global::camera_target = {0, 0, 1000};           // 注視点
Point3D<int> Global::camera_posture = {0, 1, 0};             // 姿勢
int Global::camera_viewing_angle = 30;                       // 視野角
int Global::camera_render_min = 1;                           // 最小描画距離
int Global::camera_render_max = 8000;                        // 最大描画距離

// マウス
Point2D<int> Global::current_mouse = {0, 0};
Point2D<int> Global::prev_mouse = {0, 0};
void Global::set_mouse(int x, int y, bool is_first) {
  prev_mouse = (is_first ? (Point2D<int>){x, y} : current_mouse);
  current_mouse = {x, y};
}

// 円柱ワーク
Cylinder Global::work = Cylinder(190, 10, 1080, 30);
void Global::cut() {
  work.cut(prev_mouse, current_mouse);
};
Bite Global::bite = Bite();

// 描画関数
void Global::draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  work.draw();
  bite.draw({-current_mouse.x, 0, current_mouse.y});
  glFlush();
}

// 初期化関数
void Global::init() {
  work.reset();
}
