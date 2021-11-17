#pragma once
#include "Space.hpp"
#include <GL/glut.h>
#include <Serial.hpp>
#include <iostream>

class RealBite {
  Serial serial;
  int port;

public:
  void init();
  void move(int);
};