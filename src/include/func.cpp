#include "func.h"
#include <cstring>
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <ostream>
#include <string>

#define ROWS 30
#define COLS 80

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

void GenDungeon(char map[][80], int rows, int cols) {
  for (int yy = 0; yy <= rows; yy++) {
    for (int xx = 0; xx <= cols; xx++) {
      map[yy][xx] = '#';
      mvaddch(yy, xx, '#');
    }
  }

  for (int yy = 1; yy <= rows / 2; yy++) {
    for (int xx = 11; xx <= cols / 2; xx++) {
      map[yy][xx] = ' ';
      mvaddch(yy, xx, ' ');
    }
  }
}
