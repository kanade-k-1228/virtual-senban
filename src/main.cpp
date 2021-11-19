#include <GL/glut.h>
#include <Game.hpp>

Game game;

int main(int argc, char* argv[]) {
  // GLUTの初期化
  glutInit(&argc, argv);

  // シリアル通信の初期化
  // game.init_serial();

  // ウィンドウの生成
  glutInitWindowPosition(0, 0);                                // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(game.window.size.x, game.window.size.y);  // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);                // デフォルト値
  glutCreateWindow("バーチャル旋盤");                          // ウィンドウ生成
  // glutEnterGameMode();                                         // フルスクリーンモードで開始

  // ウィンドウの初期化
  glutWarpPointer(0, 0);            // マウスカーソルを移動
  glutSetCursor(GLUT_CURSOR_NONE);  // マウスカーソル非表示
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();

  // コールバック関数登録
  // ディスプレイサイズの変更時
  glutReshapeFunc([](const int width, const int height) {
    // ウィンドウ全体をビューポートにする
    glViewport(0, 0, width, height);
    // 視点の設定
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(game.camera.position.x, game.camera.position.y, game.camera.position.z,
              game.camera.target.x, game.camera.target.y, game.camera.target.z,
              game.camera.posture.x, game.camera.posture.y, game.camera.posture.z);
    // 視野領域の設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(game.camera.viewing_angle,
                   (double)width / height,
                   game.camera.render_min,
                   game.camera.render_max);
    // 再描画
    game.draw();
  });

  // キーボードが押されたとき
  glutKeyboardFunc([](const unsigned char key, const int x, const int y) {
    if(key == 27) exit(0);  // ESCキーで終了
    if(key == ' ') game.init_object();
    game.draw();
  });

  // マウスのボタンが押されたとき
  glutMouseFunc([](const int button, const int state, const int x, const int y) {
    game.mouse.start_path(x, y);
    if(button == GLUT_LEFT_BUTTON) {
      if(state == GLUT_DOWN) {
      }
    } else if(button == GLUT_MIDDLE_BUTTON) {
    } else if(button == GLUT_RIGHT_BUTTON) {
    }
    game.draw();
  });

  // ウィンドウフォーカス時にマウスが動いたとき
  glutMotionFunc([](const int x, const int y) {
    game.mouse.next_path_point(x, y);
    // game.cut();
    game.draw();
  });

  // 非ウィンドウフォーカス時のマウスが動いたとき
  glutPassiveMotionFunc([](const int x, const int y) {
    game.mouse.next_path_point(x, y);
    game.draw();
  });

  // 描画オブジェクトの初期化と描画
  game.init_object();
  game.draw();

  // メインループ
  glutMainLoop();

  return 0;
}
