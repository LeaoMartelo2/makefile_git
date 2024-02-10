#include "func.h"
#include <cstring>
#include <curses.h>
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

void CoordDebugMessage(std::string message, bool showDebug, int y, int x) {
  const char *defaultMessageHeader = "[Debug] ";

  const char *message_cstring = message.c_str();

  if (showDebug) {

    message.insert(0, defaultMessageHeader);
    const char *message_cstring_debug = message.c_str();

    mvprintw(y, x, message_cstring_debug);
  } else {
    mvprintw(y, x, message_cstring);
  }
}
