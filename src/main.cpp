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

  char input = 0;
  int y = 15;
  int x = 40;
  char player = ACS_DIAMOND;

  int rows, cols;

  bool game = true;

  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, 1);
  raw();
  nodelay(stdscr, TRUE);

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
  }

  while (game) {
    input = getch();

    if (debugMode) {
      // this is stupid and not efficient, Too bad!
      debug_printPlayerXY(y, x);
      debug_printLastInput(input);
      debug_regenMap(input, y, x);
    }

    if (input == 27) {
      game = false;
    }

    printPlayer(y, x, player);

    // MOVE CICLE
    movePlayer(y, x, input);
  }

  refresh();
  clear();

  getmaxyx(stdscr, rows, cols);

  nodelay(stdscr, 0);
  mvprintw(rows / 2, cols / 2, "Press any key to exit.");

  getch();

  refresh();
  endwin();
  return 0;
}
