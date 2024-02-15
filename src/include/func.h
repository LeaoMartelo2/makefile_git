#ifndef FUNC_H
#define FUNC_H

#include <string>

void GenRandomRoom(char map[][81]);

void clearMap();

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void printPlayer(int &y, int &x);

void add_obj(int y, int x, char visual, char behavior = ' ',
             int color_attr = 0);

void roomPopulate_Coins();

void spawn_damage_solid(int count);

char get_behavior(int y, int x, bool &block_movement,
                  std::string &behavior_name, char side = ' ');

void spawn_spiketop(int count);

#endif
