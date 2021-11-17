#include "../hpp/resize.hpp"

void resize(const GLsizei width, const GLsizei height) {
  std::cout << "resize\t[" << width << "," << height << "]" << std::endl;

  // ウィンドウ全体をビューポートにする
  glViewport(0, 0, width, height);

  // 視点の設定
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Global::camera.position.x, Global::camera.position.y, Global::camera.position.z,
            Global::camera.target.x, Global::camera.target.y, Global::camera.target.z,
            Global::camera.posture.x, Global::camera.posture.y, Global::camera.posture.z);

  // 視野領域の設定
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(Global::camera.viewing_angle, (double)width / height, Global::camera.render_min, Global::camera.render_max);

  // 再描画
  Global::draw();
}
