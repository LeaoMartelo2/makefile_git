#include "rooms.h"
#include "func.h"
#include "map.h"
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
