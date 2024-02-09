#include "include/func.h"
#include <cstring>
#include <curses.h>
#include <iostream>
#include <ncurses.h>

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

  initscr();

  printw("Hello World!\n");

  if (debugMode) {
  }
  refresh();

  getch();

  endwin();
  return 0;
}
