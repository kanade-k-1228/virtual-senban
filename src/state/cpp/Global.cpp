#include "../hpp/Global.hpp"

Window Global::window = {{1920, 1080}};
Camera Global::camera = {{-5000, 1000, 3000}, {0, 0, 1000}, {0, 1, 0}, 30, 1, 10000};
Mouse Global::mouse = {{0, 0}, {0, 0}};
Cylinder Global::work = Cylinder(190, 10, 1080, 100);
Bite Global::bite = Bite();
RealBite Global::real_bite = RealBite(32);
Helping Global::helping = Helping();
void Global::init_serial() {
  real_bite.init();
}

void Global::init_object() {
  work.reset();
}

void Global::cut() {
  work.cut_path(display_to_cylinderical(mouse.prev), display_to_cylinderical(mouse.current));
};

void Global::add() {
  work.add_path(display_to_cylinderical(mouse.prev), display_to_cylinderical(mouse.current));
};


void Global::draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  work.draw();
  glFlush();
  helping.draw(window.size);
  glFlush();
  bite.draw(display_to_world(mouse.current));
  glFlush();
}
