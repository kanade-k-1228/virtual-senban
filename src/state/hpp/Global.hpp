#pragma once
#include "Bite.hpp"
#include "Camera.hpp"
#include "Cylinder.hpp"
#include "Mouse.hpp"
#include "Space.hpp"

namespace Global {

extern Window window;  // ウィンドウ
extern Camera camera;  // カメラ
extern Mouse mouse;    // マウス

// 円柱ワーク
extern Cylinder work;
void cut();

// バイト
extern Bite bite;

// 描画関数
void draw();

// 初期化関数
void init();
}  // namespace Global