#include "include/debug.h"
#include "include/func.h"
#include "include/map.h"
#include "include/rooms.h"
#include "include/stats.h"
#include <cstring>
#include <locale.h>
#include <ncurses.h>

// global variables

char map[31][81];

int roomY = 0;
int roomX = 0;

bool debugMode = false;

int coins = 0;
int health = 100;

int main(int argc, char *argv[]) {

  setlocale(LC_ALL, "");

  // ARGUMENT LIST
  const char *debug_mode_arg = "-debug";

  if (argc > 1) {

    if (std::strcmp(argv[1], debug_mode_arg) == 0) {
      debugMode = true;
    }
  }

  // geral use variables

  char input = 0;
  int y = 15;
  int x = 40;

  bool game = true;

  // ncurses settings

  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, 1);
  keypad(stdscr, 1);
  raw();

  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);

  // debug stuff before main game loop

  if (debugMode) {
    debug_header();
  }

  // stuff to be loaded before the main game loop

  update_menu();

  clearMap();
  mapBorder(map);

  // game loop

  while (game) {
    input = getch();
    if (input == 27) {
      game = false;
    }

    // debug mode suff that needs to be updated every loop

    if (debugMode) {
      debug_printPlayerXY(y, x);
      debug_printLastInput(input);
      debug_regenMap(input, y, x);
    }

    // general stuff that needs to be updated every game loop

    update_menu();
    gen_minimap();

    // move cycle
    movePlayer(y, x, input);
    printPlayer(y, x);
  }

  // ncurses cleaning up on loop exit

  refresh();

  endwin();
  return 0;
}
