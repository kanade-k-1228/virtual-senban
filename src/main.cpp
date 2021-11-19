#include <GL/glut.h>
#include <Game.hpp>

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);  // GLUTの初期化

#ifdef USE_SERIAL
  Game::init_serial();  // シリアル通信の初期化
#endif

  // ウィンドウの生成
  glutInitWindowPosition(0, 0);                                  // ウィンドウの場所（モニタ座標上で）
  glutInitWindowSize(Game::window.size.x, Game::window.size.y);  // ウィンドウサイズ（ピクセル単位）
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);                  // デフォルト値

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
  // ディスプレイサイズの変更時
  glutReshapeFunc([](const int width, const int height) {
    // ウィンドウ全体をビューポートにする
    glViewport(0, 0, width, height);
    // 視点の設定
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Game::camera.position.x, Game::camera.position.y, Game::camera.position.z,
              Game::camera.target.x, Game::camera.target.y, Game::camera.target.z,
              Game::camera.posture.x, Game::camera.posture.y, Game::camera.posture.z);
    // 視野領域の設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(Game::camera.viewing_angle,
                   (double)width / height,
                   Game::camera.render_min,
                   Game::camera.render_max);
    // 再描画
    Game::draw();
  });

  // キーボードが押されたとき
  glutKeyboardFunc([](const unsigned char key, const int x, const int y) {
    if(key == 27) exit(0);  // ESCキーで終了
    if(key == ' ') Game::init_object();
    Game::draw();
  });

  // マウスのボタンが押されたとき
  glutMouseFunc([](const int button, const int state, const int x, const int y) {
    Game::mouse.start_path(x, y);
    if(button == GLUT_LEFT_BUTTON) {
      if(state == GLUT_DOWN) {
      }
    } else if(button == GLUT_MIDDLE_BUTTON) {
    } else if(button == GLUT_RIGHT_BUTTON) {
    }
    Game::draw();
  });

  // ウィンドウフォーカス時にマウスが動いたとき
  glutMotionFunc([](const int x, const int y) {
    Game::mouse.next_path_point(x, y);
    Game::draw();
  });

  // 非ウィンドウフォーカス時のマウスが動いたとき
  glutPassiveMotionFunc([](const int x, const int y) {
    Game::mouse.next_path_point(x, y);
    Game::draw();
  });

  // 描画オブジェクトの初期化と描画
  Game::init_object();
  Game::draw();

  // メインループ
  glutMainLoop();

  return 0;
}
