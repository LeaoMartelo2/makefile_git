#include "stats.h"
#include <ncurses.h>

void update_menu(int health, int coins) {
  mvprintw(5, 115, "Stats: ");

  mvprintw(7, 112, "Health: ");
  attron(COLOR_PAIR(6));
  printw("%d", health);
  attroff(COLOR_PAIR(6));

  mvprintw(9, 112, "Coins: ");
  attron(COLOR_PAIR(5));
  printw("%d", coins);
  attroff(COLOR_PAIR(5));
}
