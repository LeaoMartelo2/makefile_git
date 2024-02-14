#include "stats.h"
#include <ncurses.h>

void update_menu() {

  extern int health;
  extern int coins;

  mvprintw(5, 115, "Stats: ");

  mvprintw(7, 113, "Health: ");
  attron(COLOR_PAIR(6));
  printw("%d", health);
  attroff(COLOR_PAIR(6));
  printw("     ");

  mvprintw(9, 114, "Coins: ");
  attron(COLOR_PAIR(5));
  printw("%d", coins);
  attroff(COLOR_PAIR(5));
  printw("     ");
}

void modifyCoins(int ammount) {
  extern int coins;
  coins = coins + ammount;
}

void modifyHealth(int ammount) {
  extern int health;
  health = health + ammount;
}
