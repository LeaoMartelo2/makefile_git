#include "func.h"
#include <cstdlib>
#include <curses.h>
#include <ncurses.h>

void GenRandomRoom(char map[][81], int rows, int cols) {
  // obstacles
  for (int yy = 0; yy <= rows; yy++) {
    for (int xx = 0; xx <= cols; xx++) {
      if (rand() % 99 == 0) {
        map[yy][xx] = '#';
        mvaddch(yy, xx, '#');
      }
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

  // clangd complains about map[i][81] but it compiles just fine and i see no
  // problem idk its being weird
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
