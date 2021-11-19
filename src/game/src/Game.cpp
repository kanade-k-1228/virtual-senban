#include "../include/Game.hpp"

Game::Game()
    : window({{1920, 1080}}),
      camera({{-5000, 2000, 3000}, {0, 0, 1000}, {0, 1, 0}, 30, 1, 10000}),
      mouse({{0, 0}, {0, 0}}),
      work(190, 10, 1080, 10),
      bite(),
      real_bite(32),
      helping() {}

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
