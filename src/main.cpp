#include "include/func.h"
#include <cstring>
#include <curses.h>
#include <iostream>
#include <ncurses.h>

#define ROWS 30
#define COLS 80

int main(int argc, char *argv[]) {

  // ARGUMENT LIST
  const char *debug_mode_arg = "-debug";
  bool debugMode = false;

  if (argc > 1) {

    if (std::strcmp(argv[1], debug_mode_arg) == 0) {
      ConsoleMessage("Debug mode Eneabled", true);
      debugMode = true;
      std::cin.get();
    } else {
      // pass
    }
  }

  char input;
  int y = 11;
  int x = 12;
  char player = '@';

  int rows, cols;

  rows = 30;
  cols = 80;
  char map[30][80];

  bool game = true;

  char debug;

  initscr();
  // keypad(stdscr, 1);
  noecho();
  curs_set(0);
  //  printw("row: %d, col %d", rows, cols);

  clearMap(map);

  if (debugMode) {
  }

  // GenDungeon(map, rows, cols);

  while (game) {
    /*
    mvprintw(5, 5, "Y coord: %d", y);
    mvprintw(6, 5, "X coord %d", x);
    */

    input = getch();

    movePlayer(map, y, x, input);

    mvaddch(y, x, player);
  }

  clear();

  refresh();
  endwin();
  return 0;
}
