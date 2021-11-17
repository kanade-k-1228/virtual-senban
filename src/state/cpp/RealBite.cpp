#include "../hpp/RealBite.hpp"

void RealBite::init() {
  auto list = getSerialList();
  int i = 0;
  for(const auto& info : list) {
    std::cout << i << "\t"
              << "device name:" << info.device_name() << "\t"
              << "name:" << info.port() << std::endl;
    i++;
  }
  std::cout << "Select Port Number" << std::endl;
  std::cin >> port;

  // Open Serial
  if(!serial.open(list[port], 9600)) {
    std::cout<<"Serial Connect Failed"<<std::endl;
    return;}
  //SerialInfo構造体にポート名とデバイス名が入っている
  SerialInfo info = serial.getInfo();
  std::cout << "open success" << std::endl;
  std::cout << "device name:" << info.device_name() << std::endl;
  std::cout << "name:" << info.port() << std::endl;
  return;
}

void RealBite::move(int x) {
}
