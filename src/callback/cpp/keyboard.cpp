#include "../hpp/keyboard.hpp"

void keyboard(const unsigned char key, const int x, const int y) {
  if(key == 27) exit(0);  // ESCキーで終了
  if(key == ' ') Global::init_object();
  Global::draw();
}
