#include "include/func.h"
#include <cstring>
#include <curses.h>
#include <iostream>
#include <ncurses.h>

#define ROWS 31
#define COLS 81

int main(int argc, char *argv[]) {

  // ARGUMENT LIST
  const char *debug_mode_arg = "-debug";
  bool debugMode = false;

  if (argc > 1) {

    if (std::strcmp(argv[1], debug_mode_arg) == 0) {
      //     ConsoleMessage("Debug mode Eneabled", true);
      debugMode = true;
      std::cin.get();
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
  char map[31][81];

  bool game = true;

  char debug;

  initscr();
  noecho();
  curs_set(0);

  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);

  clearMap(map);
  mapBorder(map);
  GenRandomRoom(map, rows, cols);

  if (debugMode) {
    attron(COLOR_PAIR(1));
    mvprintw(25, 115, "[Debug mode]");
    attroff(COLOR_PAIR(1));
  }

  while (game) {

    if (debugMode) {

      // this is stupid and not efficient, Too bad!
      mvprintw(27, 115, "X: ");
      attron(COLOR_PAIR(1));
      printw("%d ", x);
      attroff(COLOR_PAIR(1));
      printw("Y: ");
      attron(COLOR_PAIR(1));
      printw("%d    ", y);
      attroff(COLOR_PAIR(1));

      mvprintw(29, 115, "Last Key: ");
      attron(COLOR_PAIR(1));
      addch(input);
      addch(' ');
      attroff(COLOR_PAIR(1));
    }

    // MOVE CICLE
    input = getch();
    movePlayer(map, y, x, input);
    mvaddch(y, x, player);
  }

  clear();

  refresh();
  endwin();
  return 0;
}
