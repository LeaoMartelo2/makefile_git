#include "debug.h"
#include "func.h"
#include <ncurses.h>

void debug_printPlayerXY(int &playerY, int &playerX) {

  mvprintw(27, 115, "X: ");
  attron(COLOR_PAIR(1));
  printw("%d ", playerX);
  attroff(COLOR_PAIR(1));
  printw("Y: ");
  attron(COLOR_PAIR(1));
  printw("%d    ", playerY);
  attroff(COLOR_PAIR(1));
}

void debug_printLastInput(char input) {

  mvprintw(29, 115, "Last Key: ");

  if (input != ERR) {

    if (input == 10) {

      attron(COLOR_PAIR(1));
      addstr("\\n");
      addch(' ');
      attroff(COLOR_PAIR(1));

    } else {
      attron(COLOR_PAIR(1));
      addch(input);
      addch(' ');
      attroff(COLOR_PAIR(1));
    }
  }
}

void debug_regenMap(char input, int &playerY, int &playerX) {
  extern char map[31][81];

  mvprintw(31, 115, "Press: ");
  attron(COLOR_PAIR(1));
  printw("h");
  attroff(COLOR_PAIR(1));
  printw(" to ");
  attron(COLOR_PAIR(1));
  printw("@Re");
  attroff(COLOR_PAIR(1));
  printw("generate the map.");

  if (input == 'h') {
    clearMap(map);
    //   mapBorder(map);
    GenRandomRoom(map);
    playerY = 15;
    playerX = 40;
  }
}
