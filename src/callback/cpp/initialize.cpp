#define IS_FULL_SCREEN
// #define USE_SERIAL

#include "../hpp/initialize.hpp"

void initialize() {
  // シリアル通信の初期化
#ifdef USE_SERIAL
  Global::init_serial();
#endif

  // ウィンドウの生成
  glutInitWindowPosition(0, 0);                                      // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(Global::window.size.x, Global::window.size.y);  // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);                      // デフォルト値

#ifdef IS_FULL_SCREEN
  glutEnterGameMode();  // フルスクリーンモードで開始
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
  // glutIdleFunc(idle);                     // アイドル状態のときに実行

  // 描画オブジェクトの初期化と描画
  Global::init_object();
  Global::draw();
}
