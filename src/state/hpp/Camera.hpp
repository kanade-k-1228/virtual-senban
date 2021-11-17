#include "Space.hpp"

struct Camera {
  World position;     // 位置
  World target;       // 注視点
  World posture;      // 姿勢
  int viewing_angle;  // 視野角
  int render_min;     // 最小描画距離
  int render_max;     // 最大描画距離
};
