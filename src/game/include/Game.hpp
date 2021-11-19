#pragma once
#include "Space.hpp"
#include <GL/glut.h>
#include <Serial.hpp>
#include <bits/stdc++.h>

struct Window {
  Space::Display size;
};

struct Camera {
  Space::World position;  // 位置
  Space::World target;    // 注視点
  Space::World posture;   // 姿勢
  int viewing_angle;      // 視野角
  int render_min;         // 最小描画距離
  int render_max;         // 最大描画距離
};

struct Mouse {
  Space::Display current;
  Space::Display prev;
  void start_path(int, int);
  void next_path_point(int, int);
};

class Cylinder {
  int axial_slice_number;                                      // 軸方向の分割数 [slice]
  int axial_slice_step;                                        // 軸方向の分割間隔 [len/slice]
  int initial_radius;                                          // 加工前の半径 [len]
  int circular_slice_number;                                   // 円の分割数
  std::vector<Space::World> circular_slice_direction_vectors;  // 単位円の分割点 [cos(2pi/i),sin(2pi/i)]
  std::vector<double> radiuses;                                // 半径配列

public:
  Cylinder(int, int, int, int);
  void draw();
  void cut_point(Space::Cylinderical);
  void add_point(Space::Cylinderical);
  void cut_path(Space::Cylinderical, Space::Cylinderical);
  void add_path(Space::Cylinderical, Space::Cylinderical);
  void reset();
};

class Bite {
public:
  void draw(Space::World);
};

class RealBite {
  Serial serial;
  int port;
  int range;

public:
  RealBite(int);
  void init();
  void move(int);
};

class Helping {
public:
  Helping();
  void draw(Space::Display);
};

class Game {
public:
  Window window;       // ウィンドウ
  Camera camera;       // カメラ
  Mouse mouse;         // マウス
  Cylinder work;       // 円柱ワーク
  Bite bite;           // バイト
  RealBite real_bite;  // 実物のバイト
  Helping helping;     // 補助オブジェクト
  Game();
  void init_serial();  // シリアル通信の初期化
  void init_object();  // 描画の初期化
  void cut();          // 切削
  void add();          // 付加
  void draw();         // 描画関数
};
