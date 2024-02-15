#include "rooms.h"
#include "func.h"
#include <ncurses.h>
#include <string>

void load_room(roomTypes room_type) {

  extern char map[31][81];

  clearMap();

  Room start("Start", None);
  Room full("FULL", None);
  Room quarter("QUARTER", None);
}

void room_Start() {
  Room start("Start", None);

  start.drawName();
  start.drawDoors();
}
