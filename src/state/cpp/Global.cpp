#include "../hpp/Global.hpp"

// ウィンドウ
Window Global::window = {1920, 1080};

// カメラ
Camera Global::camera = {{-5000, 1000, 3000}, {0, 0, 1000}, {0, 1, 0}, 30, 1, 8000};

// マウス
Mouse Global::mouse = {{0, 0}, {0, 0}};

// 円柱ワーク
Cylinder Global::work = Cylinder(190, 10, 1080, 30);
void Global::cut() {
  work.cut(window_to_cylinderical(mouse.prev), window_to_cylinderical(mouse.current));
};
Bite Global::bite = Bite();

// 描画関数
void Global::draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  work.draw();
  bite.draw(window_to_world(mouse.current));
  glFlush();
}

// 初期化関数
void Global::init() {
  work.reset();
}
