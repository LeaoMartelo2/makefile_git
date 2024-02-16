#include "func.h"
#include "debug.h"
#include "stats.h"
#include <cstdlib>
#include <ncurses.h>
#include <string>

void buffer_to_screen(char buffer[][81]) {

  extern char map[31][81];

  clearMap();

  for (int y = 0; y < 31; y++) {
    for (int x = 0; x < 81; x++) {

      switch (buffer[y][x]) {
      case BEHAVIOR_SOLID_WALL:
        map[y][x] = buffer[y][x];
        mvaddch(y, x, BEHAVIOR_SOLID_WALL);
        break;

      case BEHAVIOR_DAMAGE_SOLID:
        attron(COLOR_PAIR(2));
        map[y][x] = buffer[y][x];
        mvaddch(y, x, ACS_DIAMOND);
        attroff(COLOR_PAIR(2));
        break;

      case BEHAVIOR_SPIKETOP_SOLID:
        attron(COLOR_PAIR(2));
        map[y][x] = buffer[y][x];
        mvaddch(y, x, ACS_PLMINUS);
        attroff(COLOR_PAIR(2));
        break;

      case BEHAVIOR_COLLECTIBLE_COIN:
        attron(COLOR_PAIR(5));
        map[y][x] = buffer[y][x];
        mvaddch(y, x, 'o');
        attroff(COLOR_PAIR(5));
        break;

      case BEHAVIOR_EMPTY:
        map[y][x] = buffer[y][x];
        mvaddch(y, x, BEHAVIOR_EMPTY);
        break;

      default:
        map[y][x] = BEHAVIOR_UNKNOWN;
        mvaddch(y, x, BEHAVIOR_UNKNOWN);
        break;
      }
    }
  }
}

void print_minimap(int minimap[][3]) {

  extern int roomY;
  extern int roomX;

  move(15, 115);

  for (int y = 0; y < 3; y++) {
    move(15 + y, 115);
    for (int i = 0; i < 3; i++) {
      addch('[');
      if (roomY == 0 + y && roomX == i) {
        attron(COLOR_PAIR(1));
      }
      printw("%d", minimap[0 + y][i]);
      attroff(COLOR_PAIR(1));
      addch(']');
    }
  }
}

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

  spawn_damage_solid(rand() % 5 + 1);
  spawn_spiketop(rand() % 5 + 1);
}

void roomPopulate_Coins() {

  extern char map[31][81];

  for (int yy = 1; yy < 31; yy++) {
    for (int xx = 1; xx < 81; xx++) {
      if (rand() % 999 == 0) {
        map[yy][xx] = BEHAVIOR_COLLECTIBLE_COIN;
        attron(COLOR_PAIR(5));
        attron(A_BOLD);
        mvaddch(yy, xx, 'o');
        attroff(COLOR_PAIR(5));
        attroff(A_BOLD);
      }
    }
  }
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

void spawn_spiketop(int count) {
  extern char map[31][81];

  for (int i = 0; i < count; i++) {
    int randY = rand() % 30 + 1;
    int randX = rand() % 80 + 1;

    map[randY][randX] = BEHAVIOR_SPIKETOP_SOLID;
    attron(COLOR_PAIR(2));
    mvaddch(randY, randX, ACS_PLMINUS);
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
  mapBorder(map);
}

void mapBorder(char map[][81]) {

  // might migrate this for a box(); function

  for (int i = 1; i < 81; i++) {
    map[0][i] = BEHAVIOR_SOLID_WALL;
    mvaddch(0, i, ACS_HLINE);
    map[31][i] = BEHAVIOR_SOLID_WALL;
    mvaddch(31, i, ACS_HLINE);
  }

  for (int i = 1; i < 31; i++) {
    map[i][0] = BEHAVIOR_SOLID_WALL;
    mvaddch(i, 0, ACS_VLINE);
    map[i][80] = BEHAVIOR_SOLID_WALL;
    mvaddch(i, 81, ACS_VLINE);
  }

  mvaddch(0, 0, ACS_ULCORNER);
  mvaddch(0, 81, ACS_URCORNER);
  mvaddch(31, 0, ACS_LLCORNER);
  mvaddch(31, 81, ACS_LRCORNER);
}

void printPlayer(int &y, int &x) {

  attron(COLOR_PAIR(1));
  // mvaddch(y, x, player);
  mvaddch(y, x, ACS_DIAMOND);
  attroff(COLOR_PAIR(1));
}

char get_behavior(int y, int x, bool &block_movement,
                  std::string &behavior_name, char side) {

  extern char map[31][81];

  if (map[y][x] == BEHAVIOR_SOLID_WALL) {
    block_movement = true;
    behavior_name = "BEHAVIOR_SOLID_WALL";
    return BEHAVIOR_SOLID_WALL;
  }

  if (map[y][x] == BEHAVIOR_COLLECTIBLE_COIN) {
    block_movement = false;
    modifyCoins(1);
    behavior_name = "BEHAVIOR_COLLECTIBLE_COIN";
    return BEHAVIOR_COLLECTIBLE_COIN;
  }

  if (map[y][x] == BEHAVIOR_DAMAGE_SOLID) {
    block_movement = true;
    modifyHealth(-1);
    behavior_name = "BEHAVIOR_DAMAGE_SOLID";
    return BEHAVIOR_DAMAGE_SOLID;
  }

  if (map[y][x] == BEHAVIOR_SPIKETOP_SOLID) {
    block_movement = true;
    if (side == 's') {
      modifyHealth(-1);
    }
    behavior_name = "BEHAVIOR_SPIKETOP_SOLID";
    return BEHAVIOR_SPIKETOP_SOLID;
  }

  if (map[y][x] == BEHAVIOR_EMPTY) {
    block_movement = false;
    behavior_name = "BEHAVIOR_EMPTY";
    return BEHAVIOR_EMPTY;
  }

  // fallback option if the game does not know what you colided with
  block_movement = false;
  behavior_name = "BEHAVIOR_UNKNOWN";
  return BEHAVIOR_UNKNOWN;
}

void movePlayer(int &y, int &x, char input) {

  extern bool debugMode;

  bool cancel_movement = false;
  char localcheck;
  std::string behavior_name;

  switch (input) {
  case 'w':

    localcheck = get_behavior(y - 1, x, cancel_movement, behavior_name, input);

    if (localcheck != BEHAVIOR_EMPTY) {
      if (debugMode)
        debug_log_colision("Colision with bottom of ", behavior_name.c_str());
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      y--;
    }
    break;

  case 's':

    localcheck = get_behavior(y + 1, x, cancel_movement, behavior_name, input);

    if (localcheck != BEHAVIOR_EMPTY) {
      if (debugMode)
        debug_log_colision("Colision with top of ", behavior_name.c_str());
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      y++;
    }

    break;

  case 'a':

    localcheck = get_behavior(y, x - 1, cancel_movement, behavior_name, input);

    if (localcheck != BEHAVIOR_EMPTY) {
      if (debugMode)
        debug_log_colision("Colision with right side of ",
                           behavior_name.c_str());
    }

    if (!cancel_movement) {
      add_obj(y, x, BEHAVIOR_EMPTY, BEHAVIOR_EMPTY);
      x--;
    }

    break;

  case 'd':

    localcheck = get_behavior(y, x + 1, cancel_movement, behavior_name, input);

    if (localcheck != BEHAVIOR_EMPTY) {
      if (debugMode)
        debug_log_colision("Colision with left side of ",
                           behavior_name.c_str());
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
