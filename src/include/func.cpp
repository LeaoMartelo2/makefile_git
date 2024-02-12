#include "func.h"
#include <cstdlib>
#include <ncurses.h>

void GenRandomRoom(char map[][81]) {
  // obstacles
  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      if (rand() % 99 == 0) {
        map[yy][xx] = '#';
        attron(COLOR_PAIR(2));
        mvaddch(yy, xx, '#');
        attroff(COLOR_PAIR(2));
      }
    }
  }
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

  if (input != ERR) {

    if (input == 10) {

      attron(COLOR_PAIR(1));
      addstr("\\n");
      addch(' ');
      attroff(COLOR_PAIR(1));

    } else {
      attron(COLOR_PAIR(1));
      addch(input);
      addch(' ');
      attroff(COLOR_PAIR(1));
    }
  }
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
    //   mapBorder(map);
    GenRandomRoom(map);
    playerY = 15;
    playerX = 40;
  }
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
