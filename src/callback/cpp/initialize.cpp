#define IS_FULL_SCREEN

#include "../hpp/initialize.hpp"

void initialize() {
  Global::init_serial();

  // ウィンドウの生成
  glutInitWindowPosition(0, 0);                  // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(1920, 1080);                // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  // デフォルト値

#ifdef IS_FULL_SCREEN
  glutEnterGameMode();  // フルスクリーンモード
#else
  glutCreateWindow("バーチャル旋盤");  // ウィンドウ生成
#endif

  // ウィンドウの初期化
  glutWarpPointer(0, 0);            // マウスカーソルを移動
  glutSetCursor(GLUT_CURSOR_NONE);  // マウスカーソル非表示
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();

  // コールバック関数登録
  glutReshapeFunc(resize);                // ディスプレイサイズの変更
  glutKeyboardFunc(keyboard);             // キーボードが押されたとき
  glutMouseFunc(mouse);                   // マウスのボタンが押されたとき
  glutMotionFunc(motion);                 // ウィンドウフォーカス時にマウスが動いたとき
  glutPassiveMotionFunc(passive_motion);  // 非ウィンドウフォーカス時のマウスが動いたとき
  glutIdleFunc(idle);                     // アイドル状態のときに実行

  Global::init_object();
}
