#include "func.h"
#include <iostream>
#include <ostream>
#include <string>

void GameMessage(std::string message, bool displayHeader) {

  std::string defaultMessageHeader = "[Debug] ";

  if (displayHeader == false) {
    std::cout << message << std::endl;
  }

  if (displayHeader == true) {
    std::cout << defaultMessageHeader << message << std::endl;
  }
}
