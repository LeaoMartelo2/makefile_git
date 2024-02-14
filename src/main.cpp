#include "include/debug.h"
#include "include/func.h"
#include "include/stats.h"
#include <cstring>
#include <locale.h>
#include <ncurses.h>

#define ROWS 31
#define COLS 81

char map[31][81];

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

  char input = 0;
  int y = 15;
  int x = 40;
  char player = ACS_DIAMOND;

  int rows, cols;

  bool game = true;

  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, 1);
  raw();

  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);

  if (debugMode) {
    debug_header();
  }

  update_menu();

  clearMap();
  mapBorder(map);

  while (game) {
    input = getch();
    if (input == 27) {
      game = false;
    }

    if (debugMode) {
      debug_printPlayerXY(y, x);
      debug_printLastInput(input);
      debug_regenMap(input, y, x);
    }

    update_menu();

    // move cycle
    movePlayer(y, x, input);
    printPlayer(y, x);
  }

  refresh();

  endwin();
  return 0;
}
