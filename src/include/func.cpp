#include "func.h"
#include <cstdlib>
#include <ncurses.h>

void add_obj(int y, int x, char visual, char behavior, int color_attr) {

  extern char map[31][81];

  map[y][x] = behavior;
  attron(COLOR_PAIR(color_attr));
  mvaddch(y, x, visual);
  attroff(COLOR_PAIR(color_attr));
}

void GenRandomRoom(char map[][81]) {
  // obstacles

  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      if (rand() % 99 == 0) {
        map[yy][xx] = BEHAVIOR_SOLID_WALL;
        mvaddch(yy, xx, BEHAVIOR_SOLID_WALL);
      }
    }
  }

  int random_squares = rand() % 5 + 1;

  for (int i = 0; i < random_squares + 1; i++) {

    int rand0 = rand() % 26 + 1;
    int rand1 = rand() % 73 + 1;

    // top
    map[rand0][rand1] = BEHAVIOR_SOLID_WALL;
    mvaddch(rand0, rand1, ACS_ULCORNER);

    for (int j = 1; j < 6; j++) {
      map[rand0][rand1 + j] = BEHAVIOR_SOLID_WALL;
      mvaddch(rand0, rand1 + j, ACS_HLINE);
    }

    map[rand0][rand1 + 6] = BEHAVIOR_SOLID_WALL;
    mvaddch(rand0, rand1 + 6, ACS_URCORNER);

    // bottom
    map[rand0 + 4][rand1] = BEHAVIOR_SOLID_WALL;
    mvaddch(rand0 + 4, rand1, ACS_LLCORNER);

    for (int j = 1; j < 6; j++) {
      map[rand0 + 4][rand1 + j] = BEHAVIOR_SOLID_WALL;
      mvaddch(rand0 + 4, rand1 + j, ACS_HLINE);
    }

    map[rand0 + 4][rand1 + 6] = BEHAVIOR_SOLID_WALL;
    mvaddch(rand0 + 4, rand1 + 6, ACS_LRCORNER);

    // left side

    for (int j = 1; j < 4; j++) {
      map[rand0 + j][rand1] = BEHAVIOR_SOLID_WALL;
      mvaddch(rand0 + j, rand1, ACS_VLINE);
    }

    // right side

    for (int j = 1; j < 4; j++) {
      map[rand0 + j][rand1 + 6] = BEHAVIOR_SOLID_WALL;
      mvaddch(rand0 + j, rand1 + 6, ACS_VLINE);
    }
  }
}

void clearMap(char map[][81]) {
  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      map[yy][xx] = BEHAVIOR_EMPTY;
      mvaddch(yy, xx, BEHAVIOR_EMPTY);
    }
  }
}

void mapBorder(char map[][81]) {

  // might migrate this for a box(); function

  for (int i = 0; i < 82; i++) {
    map[0][i] = BEHAVIOR_SOLID_WALL;
    mvaddch(0, i, ACS_HLINE);
    map[31][i] = BEHAVIOR_SOLID_WALL;
    mvaddch(31, i, ACS_HLINE);
  }

  for (int i = 0; i < 32; i++) {
    map[i][0] = BEHAVIOR_SOLID_WALL;
    mvaddch(i, 0, ACS_VLINE);
    map[i][81] = BEHAVIOR_SOLID_WALL;
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

// char check_coord(int y_offset, int x_offset)

void movePlayer(int &y, int &x, char input) {

  extern char map[31][81];

  switch (input) {
  case 'w':
    if (map[y - 1][x] == BEHAVIOR_SOLID_WALL) {
    } else {
      mvaddch(y, x, BEHAVIOR_EMPTY);
      y--;
    }
    break;

  case 's':
    if (map[y + 1][x] == BEHAVIOR_SOLID_WALL) {
    } else {
      mvaddch(y, x, BEHAVIOR_EMPTY);
      y++;
    }
    break;

  case 'a':
    if (map[y][x - 1] == BEHAVIOR_SOLID_WALL) {
    } else {
      mvaddch(y, x, BEHAVIOR_EMPTY);
      x--;
    }
    break;

  case 'd':
    if (map[y][x + 1] == BEHAVIOR_SOLID_WALL) {
    } else {
      mvaddch(y, x, BEHAVIOR_EMPTY);
      x++;
    }
    break;
  default:
    break;
  }
}
