#include <GL/glut.h>
#include <initialize.hpp>

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);  // GLUTの初期化
  initialize();    // 初期化
  glutMainLoop();  // メインループ

  return 0;
}
