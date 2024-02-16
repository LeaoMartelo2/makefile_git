#ifndef ROOMS_H
#define ROOMS_H

#include "debug.h"
#include "func.h"
#include <ncurses.h>
#include <string>

void room_Start();

void gen_minimap();

void drawName(std::string room_name);

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
};

#endif
