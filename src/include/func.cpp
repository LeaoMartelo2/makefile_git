#include "func.h"
#include <iostream>
#include <ncurses.h>
#include <ostream>
#include <string>

void ConsoleMessage(std::string message, bool displayHeader) {

  std::string defaultMessageHeader = "[Debug] ";

  if (displayHeader) {
    std::cout << defaultMessageHeader << message << std::endl;
  } else {
    std::cout << message << std::endl;
  }
}

// displays a debug message at X, Y coords on a ncurses screen
void CoordDebugMessage(const char *message, bool showDebug, int y, int x) {
  const char *defaultMessageHeader = "[Debug] ";

  if (showDebug) {
    // ncurses magic to show the message with the header at X, Y
  } else {
    // ncurses magic to show the message without the header at X, Y
  }
}
