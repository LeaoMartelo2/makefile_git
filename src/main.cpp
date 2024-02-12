#include "include/func.h"
#include <cstring>
#include <locale.h>
#include <ncurses.h>

#define ROWS 31
#define COLS 81

char map[31][81];

int main(int argc, char *argv[]) {

  setlocale(LC_ALL, "");

  // ARGUMENT LIST
  const char *debug_mode_arg = "-debug";
  bool debugMode = false;

  if (argc > 1) {

    if (std::strcmp(argv[1], debug_mode_arg) == 0) {
      debugMode = true;
      //     std::cin.get();
    } else {
      // pass
    }
  }

  char input;
  int y = 15;
  int x = 40;
  char player = '@';

  int rows, cols;

  rows = 31;
  cols = 81;

  bool game = true;

  char debug;

  initscr();
  noecho();
  curs_set(0);

  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  clearMap(map);
  mapBorder(map);
  GenRandomRoom(map);

  if (debugMode) {
    attron(COLOR_PAIR(1));
    mvprintw(25, 115, "[Debug mode]");
    attroff(COLOR_PAIR(1));
    map[30][80] = ' ';
  }

  while (game) {

    if (debugMode) {
      // this is stupid and not efficient, Too bad!
      debug_printPlayerXY(y, x);
      debug_printLastInput(input);
      debug_regenMap(input, y, x);
    }

    mvaddch(y, x, ACS_BOARD);

    // MOVE CICLE
    input = getch();
    movePlayer(y, x, input);
  }

  clear();

  refresh();
  endwin();
  return 0;
}
