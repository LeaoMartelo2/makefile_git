#include "func.h"
#include <cstdlib>
#include <ncurses.h>

void GenRandomRoom(char map[][81]) {
  // obstacles
  for (int yy = 0; yy < 32; yy++) {
    for (int xx = 0; xx < 82; xx++) {
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

  for (int i = 0; i < 32; i++) {
    map[i][0] = '#';
    mvaddch(i, 0, '#');
    map[i][81] = '#';
    mvaddch(i, 81, '#');
  }
}

void debug_printPlayerXY(int &playerY, int &playerX) {

  mvprintw(27, 115, "X: ");
  attron(COLOR_PAIR(1));
  printw("%d ", playerX);
  attroff(COLOR_PAIR(1));
  printw("Y: ");
  attron(COLOR_PAIR(1));
  printw("%d    ", playerY);
  attroff(COLOR_PAIR(1));
}

void debug_printLastInput(char input) {

  mvprintw(29, 115, "Last Key: ");
  attron(COLOR_PAIR(1));
  addch(input);
  addch(' ');
  attroff(COLOR_PAIR(1));
}

void debug_regenMap(char input, int &playerY, int &playerX) {
  extern char map[31][81];

  mvprintw(31, 115, "Press: ");
  attron(COLOR_PAIR(1));
  printw("h");
  attroff(COLOR_PAIR(1));
  printw(" to re-generate the map.");

  if (input == 'h') {
    clearMap(map);
    mapBorder(map);
    GenRandomRoom(map);
    playerY = 15;
    playerX = 40;
  }
}

void movePlayer(int &y, int &x, char input) {

  extern char map[31][81];

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
