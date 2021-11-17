#pragma once
#include "Bite.hpp"
#include "Camera.hpp"
#include "Cylinder.hpp"
#include "Helping.hpp"
#include "Mouse.hpp"
#include "RealBite.hpp"
#include "Space.hpp"
#include "Window.hpp"

namespace Global {
// 状態
extern Window window;       // ウィンドウ
extern Camera camera;       // カメラ
extern Mouse mouse;         // マウス
extern Cylinder work;       // 円柱ワーク
extern Bite bite;           // バイト
extern RealBite real_bite;  // 実物のバイト
extern Helping helping;     // 補助オブジェクト
void init_serial();         // シリアル通信の初期化
void init_object();         // 描画の初期化
void cut();                 // 切削
void add();                 // 付加
void draw();                // 描画関数
}  // namespace Global
