#ifndef ROOMS_H
#define ROOMS_H

#include "debug.h"
#include "func.h"
#include <ncurses.h>
#include <string>

enum Doors {
  None = 0,
  Up = 1,
  Down = 2,
  Left = 3,
  Right = 4

};

enum roomTypes {
  Start = 0,
  Full = 1,
  Quarter = 2

};

class Room {
private:
public:
  Doors door = None;
  std::string room_name = "Default name";
  char map_preset[31][81];
  bool visited_status = false;

private: // functions
public:  // functions
  Room(std::string room_name, Doors door /*, char map_preset[][81]*/) {

    this->room_name = room_name;
    this->door = door;

    for (int i = 1; i < 31; i++) {
      for (int j = 1; j < 81; j++) {
        this->map_preset[i][j] = map_preset[i][j];
      }
    }
  }

  void drawName() {
    int name_size = room_name.size();
    attron(COLOR_PAIR(1));
    mvaddstr(0, (40 - name_size / 2), room_name.c_str());
    attroff(COLOR_PAIR(1));
  }

  void drawDoors() {
    if (door != None) {
      mvprintw(12, 40, "DOOR");
    }
  }

  void print_preset() {

    extern char map[31][81];

    clearMap();
    drawName();

    for (int i = 1; i < 31; i++) {
      for (int j = 1; j < 81; j++) {
        map[i][j] = map_preset[i][j];
      }
    }
  }
};

void room_Start();

#endif
