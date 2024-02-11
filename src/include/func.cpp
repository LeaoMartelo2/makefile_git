#include "func.h"
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

    // mvprintw(y, x, message_cstring_debug);
  } else {
    // mvprintw(y, x, message_cstring);
  }
}

void GenDungeon(char map[][81], int rows, int cols) {
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

void clearMap(char map[][81]) {
  for (int yy = 0; yy < 32; yy++) {
    for (int xx = 0; xx < 82; xx++) {
      map[yy][xx] = ' ';
      mvaddch(yy, xx, ' ');
    }
  }
}

void mapBorder(char map[][81]) {
  for (int i = 0; i < 82; i++) {
    map[0][i] = '#';
    mvaddch(0, i, '#');
    map[31][i] = '#';
    mvaddch(31, i, '#');
  }

  for (int i = 0; i < 32; i++) {
    map[i][0] = '#';
    mvaddch(i, 0, '#');
    map[i][81] = '#';
    mvaddch(i, 81, '#');
  }
}

void movePlayer(char map[][81], int &y, int &x, char input) {

  switch (input) {
  case 'w':
    if (map[y - 1][x] == ' ') {
      mvaddch(y, x, ' ');
      y--;
    }
    break;

  case 's':
    if (map[y + 1][x] == ' ') {
      mvaddch(y, x, ' ');
      y++;
    }
    break;

  case 'a':
    if (map[y][x - 1] == ' ') {
      mvaddch(y, x, ' ');
      x--;
    }
    break;

  case 'd':
    if (map[y][x + 1] == ' ') {
      mvaddch(y, x, ' ');
      x++;
    }
    break;
  default:
    break;
  }
}
