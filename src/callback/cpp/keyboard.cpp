#include "../hpp/keyboard.hpp"

void keyboard(const unsigned char key, const int x, const int y) {
  std::cout << "key\t" << key << std::endl;
  if(key == 27) exit(0);  // ESCキーで終了
  if(key == ' ') {
    Global::work.reset();
    Global::draw();
  }
}
