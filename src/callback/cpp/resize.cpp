#include "../hpp/resize.hpp"

void resize(const GLsizei width, const GLsizei height) {
  std::cout << "resize\t[" << width << "," << height << "]" << std::endl;

  // ウィンドウ全体をビューポートにする
  glViewport(0, 0, width, height);

  // 視点の設定
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Global::camera_position.x, Global::camera_position.y, Global::camera_position.z,
            Global::camera_target.x, Global::camera_target.y, Global::camera_target.z,
            Global::camera_posture.x, Global::camera_posture.y, Global::camera_posture.z);

  // 視野領域の設定
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(Global::camera_viewing_angle, (double)width / height, Global::camera_render_min, Global::camera_render_max);
}
