#include <GL/glut.h>
#include <display.hpp>
#include <initialize.hpp>
#include <iostream>
#include <keyboard.hpp>
#include <motion.hpp>
#include <mouse.hpp>
#include <passive_motion.hpp>
#include <resize.hpp>

int main(int argc, char* argv[]) {
  // トップレベルウィンドウ生成
  glutInit(&argc, argv);                         // GLUTの初期化
  glutInitWindowPosition(100, 100);              // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(800, 600);                  // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  // デフォルト値
  glutCreateWindow("OpenGL Test");               // ウィンドウ生成

  // コールバック関数登録
  glutDisplayFunc(display);               // ディスプレイの再描画
  glutReshapeFunc(resize);                // ディスプレイサイズの変更
  glutMouseFunc(mouse);                   // マウスボタン
  glutMotionFunc(motion);                 // マウスの動き
  glutPassiveMotionFunc(passive_motion);  // マウスの動く
  glutKeyboardFunc(keyboard);             // キーボード

  initialize();    // 初期化
  glutMainLoop();  // メインループ

  return 0;
}
