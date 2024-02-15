#include "rooms.h"
#include "func.h"
#include <ncurses.h>

void load_room(unsigned short room_id) {

  extern char map[31][81];

  clearMap();

  if (room_id == 1) {
    presetRoom_1();
  }
}

void presetRoom_1() {
  attron(COLOR_PAIR(1));
  mvprintw(0, 33, "STARTING ROOM");
  attroff(COLOR_PAIR(1));
}
