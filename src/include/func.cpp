#include "func.h"
#include <cstdlib>
#include <ncurses.h>

void GenRandomRoom(char map[][81]) {
  // obstacles

  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      if (rand() % 99 == 0) {
        map[yy][xx] = '#';
        mvaddch(yy, xx, '#');
      }
    }
  }

  int rand0 = rand() % 26 + 1;
  int rand1 = rand() % 73 + 1;

  // top
  map[rand0][rand1] = '#';
  mvaddch(rand0, rand1, ACS_ULCORNER);
  map[rand0][rand1 + 1] = '#';
  mvaddch(rand0, rand1 + 1, ACS_HLINE);
  map[rand0][rand1 + 2] = '#';
  mvaddch(rand0, rand1 + 2, ACS_HLINE);
  map[rand0][rand1 + 3] = '#';
  mvaddch(rand0, rand1 + 3, ACS_HLINE);
  map[rand0][rand1 + 4] = '#';
  mvaddch(rand0, rand1 + 4, ACS_HLINE);
  map[rand0][rand1 + 5] = '#';
  mvaddch(rand0, rand1 + 5, ACS_HLINE);
  map[rand0][rand1 + 6] = '#';
  mvaddch(rand0, rand1 + 6, ACS_URCORNER);

  // bottom
  map[rand0 + 4][rand1] = '#';
  mvaddch(rand0 + 4, rand1, ACS_LLCORNER);
  map[rand0 + 4][rand1 + 1] = '#';
  mvaddch(rand0 + 4, rand1 + 1, ACS_HLINE);
  map[rand0 + 4][rand1 + 2] = '#';
  mvaddch(rand0 + 4, rand1 + 2, ACS_HLINE);
  map[rand0 + 4][rand1 + 3] = '#';
  mvaddch(rand0 + 4, rand1 + 3, ACS_HLINE);
  map[rand0 + 4][rand1 + 4] = '#';
  mvaddch(rand0 + 4, rand1 + 4, ACS_HLINE);
  map[rand0 + 4][rand1 + 5] = '#';
  mvaddch(rand0 + 4, rand1 + 5, ACS_HLINE);
  map[rand0 + 4][rand1 + 6] = '#';
  mvaddch(rand0 + 4, rand1 + 6, ACS_LRCORNER);

  // left side

  map[rand0 + 1][rand1] = '#';
  mvaddch(rand0 + 1, rand1, ACS_VLINE);
  map[rand0 + 2][rand1] = '#';
  mvaddch(rand0 + 2, rand1, ACS_VLINE);
  map[rand0 + 3][rand1] = '#';
  mvaddch(rand0 + 3, rand1, ACS_VLINE);

  // right side

  map[rand0 + 1][rand1 + 6] = '#';
  mvaddch(rand0 + 1, rand1 + 6, ACS_VLINE);
  map[rand0 + 2][rand1 + 4] = '#';
  mvaddch(rand0 + 2, rand1 + 6, ACS_VLINE);
  map[rand0 + 3][rand1 + 4] = '#';
  mvaddch(rand0 + 3, rand1 + 6, ACS_VLINE);
}

void clearMap(char map[][81]) {
  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      map[yy][xx] = ' ';
      mvaddch(yy, xx, ' ');
    }
  }
}

void mapBorder(char map[][81]) {

  // might migrate this for a box(); function

  for (int i = 0; i < 82; i++) {
    map[0][i] = '#';
    mvaddch(0, i, ACS_HLINE);
    map[31][i] = '#';
    mvaddch(31, i, ACS_HLINE);
  }

  for (int i = 0; i < 32; i++) {
    map[i][0] = '#';
    mvaddch(i, 0, ACS_VLINE);
    map[i][81] = '#';
    mvaddch(i, 81, ACS_VLINE);
  }

  mvaddch(0, 0, ACS_ULCORNER);
  mvaddch(0, 81, ACS_URCORNER);
  mvaddch(31, 0, ACS_LLCORNER);
  mvaddch(31, 81, ACS_LRCORNER);
}

void printPlayer(int &y, int &x, char player) {

  attron(COLOR_PAIR(1));
  // mvaddch(y, x, player);
  mvaddch(y, x, ACS_DIAMOND);
  attroff(COLOR_PAIR(1));
}

void movePlayer(int &y, int &x, char input) {

  extern char map[31][81];

  switch (input) {
  case 'w':
    if (map[y - 1][x] == '#') {
    } else {
      mvaddch(y, x, ' ');
      y--;
    }
    break;

  case 's':
    if (map[y + 1][x] == '#') {
    } else {
      mvaddch(y, x, ' ');
      y++;
    }
    break;

  case 'a':
    if (map[y][x - 1] == '#') {
    } else {
      mvaddch(y, x, ' ');
      x--;
    }
    break;

  case 'd':
    if (map[y][x + 1] == '#') {
    } else {
      mvaddch(y, x, ' ');
      x++;
    }
    break;
  default:
    break;
  }
}
