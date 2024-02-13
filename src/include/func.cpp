#include "func.h"
#include "debug.h"
#include <cstdlib>
#include <ncurses.h>

void add_obj(int y, int x, char visual, char behavior, int color_attr) {

  extern char map[31][81];

  // make sure not to write outside the array, if given coords are out the map
  // turn it in to a visual only obj

  if (y > 31 || x > 81) {
    attron(COLOR_PAIR(color_attr));
    mvaddch(y, x, visual);
    attroff(COLOR_PAIR(color_attr));
  } else {

    map[y][x] = behavior;
    attron(COLOR_PAIR(color_attr));
    mvaddch(y, x, visual);
    attroff(COLOR_PAIR(color_attr));
  }
}

void GenRandomRoom(char map[][81]) {

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

  roomPopulate_Coins();
}

void roomPopulate_Coins() {

  extern char map[31][81];

  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      if (rand() % 999 == 0) {
        map[yy][xx] = BEHAVIOR_COLLECTIBLE_COIN;
        attron(COLOR_PAIR(5));
        attron(A_BOLD);
        mvaddch(yy, xx, '.');
        attroff(COLOR_PAIR(5));
        attroff(A_BOLD);
      }
    }
  }
}

void modifyCoins(int ammount) {
  extern int coins;

  coins = coins + ammount;
}

void modifyHealth(int ammount) {
  extern int health;

  health = health + ammount;
}

void spawn_damage_solid(int count) {

  extern char map[31][81];

  for (int i = 0; i < count; i++) {

    int randY = rand() % 30 + 1;
    int randX = rand() % 80 + 1;

    map[randY][randX] = BEHAVIOR_DAMAGE_SOLID;
    attron(COLOR_PAIR(2));
    mvaddch(randY, randX, ACS_DIAMOND);
    attroff(COLOR_PAIR(2));
  }
}

void clearMap() {

  extern char map[31][81];

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

char get_behavior(int y, int x, bool &block_movement) {

  extern char map[31][81];

  if (map[y][x] == BEHAVIOR_SOLID_WALL) {
    block_movement = true;
    return BEHAVIOR_SOLID_WALL;
  }

  if (map[y][x] == BEHAVIOR_COLLECTIBLE_COIN) {
    block_movement = false;
    modifyCoins(1);
    return BEHAVIOR_COLLECTIBLE_COIN;
  }

  if (map[y][x] == BEHAVIOR_DAMAGE_SOLID) {
    block_movement = true;
    modifyHealth(-1);
    return BEHAVIOR_DAMAGE_SOLID;
  }

  if (map[y][x] == BEHAVIOR_EMPTY) {
    block_movement = false;
    return BEHAVIOR_EMPTY;
  }

  // last ditch effort if the game does not know what you colided with
  block_movement = false;
  return BEHAVIOR_UNKNOWN;
}

void movePlayer(int &y, int &x, char input) {

  extern char map[31][81];
  extern int coins;
  extern int health;

  bool cancel_movement = false;
  char localcheck;

  switch (input) {
  case 'w':

    localcheck = get_behavior(y - 1, x, cancel_movement);

    if (localcheck != BEHAVIOR_EMPTY) {
      debug_log_colision("Colision with bottom of ", localcheck);
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      y--;
    }
    break;

  case 's':

    localcheck = get_behavior(y + 1, x, cancel_movement);

    if (localcheck != BEHAVIOR_EMPTY) {
      debug_log_colision("Colision with top of ", localcheck);
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      y++;
    }

    break;

  case 'a':

    localcheck = get_behavior(y, x - 1, cancel_movement);

    if (localcheck != BEHAVIOR_EMPTY) {

      debug_log_colision("Colision with right side of ", localcheck);
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      x--;
    }

    break;

  case 'd':

    localcheck = get_behavior(y, x + 1, cancel_movement);

    if (localcheck != BEHAVIOR_EMPTY) {
      debug_log_colision("Colision with left side of ", localcheck);
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      x++;
    }
    break;
  default:
    break;
  }
}
