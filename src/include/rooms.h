#ifndef ROOMS_H
#define ROOMS_H

#include "debug.h"
#include "func.h"
#include "map.h"
#include <ncurses.h>
#include <string>

void gen_minimap();

void start_rooms();

class Room {
public:
  char map_buffer[31][81];
  std::string room_name;

  int room_id = 0;

  int minimapX;
  int minimapY;

  Room(std::string room_name, int minimapY, int minimapX) {
    this->room_name = room_name;
    this->minimapY = minimapY;
    this->minimapX = minimapX;
  }

  void load() {
    /*turn down for what*/
    buffer_to_screen(map_buffer);
  }

  void drawName() {
    attron(COLOR_PAIR(1));
    mvaddstr(0, (40 - room_name.size() / 2), room_name.c_str());
    attroff(COLOR_PAIR(1));
  }

  void recieve_buffer(char preset_buffer[][81]) {

    for (int y = 0; y < 31; y++) {
      for (int x = 0; x < 81; x++) {
        this->map_buffer[y][x] = preset_buffer[y][x];
      }
    }
  }
};

#endif
