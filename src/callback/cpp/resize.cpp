#include "../hpp/resize.hpp"

void resize(const GLsizei width, const GLsizei height) {
  std::cout << "resize\t[" << width << "," << height << "]" << std::endl;

  // ウィンドウ全体をビューポートにする
  glViewport(0, 0, width, height);

  // 視点の設定
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(-200.0, 0.0, 150.0,  // 視点
            0.0, 0.0, 50.0,      // 注視点
            0.0, 1.0, 0.0);      // 姿勢

  // 視野領域の設定
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0,                    // 視野角
                 (double)width / height,  // アスペクト比
                 1.0,                     // 描画範囲の開始位置
                 1000.0);                 // 描画範囲の終了位置
}
