// #define IS_FULL_SCREEN

#include <GL/glut.h>
#include <callback.hpp>

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);  // GLUTの初期化

  // ウィンドウの生成
  glutInitWindowPosition(0, 0);                  // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(1920, 1080);                // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  // デフォルト値

#ifdef IS_FULL_SCREEN
  glutEnterGameMode();  // フルスクリーンモード
#else
  glutCreateWindow("バーチャル旋盤");  // ウィンドウ生成
#endif

  // コールバック関数登録
  // https://www.opengl.org/resources/libraries/glut/spec3/node45.html
  glutDisplayFunc(display);  // ディスプレイの再描画
  // glutOverlayDisplayFunc();
  glutReshapeFunc(resize);                // ディスプレイサイズの変更
  glutKeyboardFunc(keyboard);             // キーボード
  glutMouseFunc(mouse);                   // マウスボタン
  glutMotionFunc(motion);                 // マウスの動き
  glutPassiveMotionFunc(passive_motion);  // マウスの動く
  // glutVisibilityFunc();
  // glutEntryFunc();
  // glutSpecialFunc();
  // glutSpaceballMotionFunc();
  // glutSpaceballRotateFunc();
  // glutSpaceballButtonFunc();
  // glutButtonBoxFunc();
  // glutDialsFunc();
  // glutTabletMotionFunc();
  // glutTabletButtonFunc();
  // glutMenuStatusFunc();
  glutIdleFunc(idle);  // アイドル状態のときに実行
  // glutTimerFunc();

  initialize();    // 初期化
  glutMainLoop();  // メインループ

  return 0;
}
