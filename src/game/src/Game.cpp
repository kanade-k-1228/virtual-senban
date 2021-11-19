#include "../include/Game.hpp"

Window Game::window = {{1920, 1080}};
Camera Game::camera = {{-5000, 1000, 3000}, {0, 0, 1000}, {0, 1, 0}, 30, 1, 10000};
Mouse Game::mouse = {{0, 0}, {0, 0}};
Cylinder Game::work = Cylinder(190, 10, 1080, 10);
Bite Game::bite = Bite();
RealBite Game::real_bite = RealBite(32);
Helping Game::helping = Helping();
void Game::init_serial() {
  real_bite.init();
}

void Game::init_object() {
  work.reset();
}

void Game::cut() {
  work.cut_path(display_to_cylinderical(mouse.prev), display_to_cylinderical(mouse.current));
};

void Game::add() {
  work.add_path(display_to_cylinderical(mouse.prev), display_to_cylinderical(mouse.current));
};

void Game::draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  work.draw();
  glFlush();
  helping.draw(window.size);
  glFlush();
  bite.draw(display_to_world(mouse.current));
  glFlush();
}
