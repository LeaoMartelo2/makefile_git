#include "rooms.h"
#include "func.h"
#include <ncurses.h>

enum Door_side {

  Up = 0,
  Down = 1,
  Left = 2,
  Right = 3

};

void gen_minimap() {

  int mini_map[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mini_map[i][j] = 0;
    }
  }

  print_minimap(mini_map);
}

void drawName(std::string room_name) {
  int name_size = room_name.size();
  attron(COLOR_PAIR(1));
  mvaddstr(0, (40 - name_size / 2), room_name.c_str());
  attroff(COLOR_PAIR(1));
}
