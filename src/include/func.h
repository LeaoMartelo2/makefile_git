#ifndef FUNC_H
#define FUNC_H

#include <string>

#define BEHAVIOR_SOLID_WALL '#'
#define BEHAVIOR_COLLECTIBLE_COIN '$'
#define BEHAVIOR_DAMAGE_SOLID 'D'
#define BEHAVIOR_SPIKETOP_SOLID '^'
#define BEHAVIOR_EMPTY ' '
#define BEHAVIOR_UNKNOWN 'U'

void GenRandomRoom(char map[][81]);

void clearMap();

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void printPlayer(int &y, int &x);

void add_obj(int y, int x, char visual, char behavior = ' ',
             int color_attr = 0);

void roomPopulate_Coins();

void spawn_damage_solid(int count);

void modifyCoins(int ammount);

void modifyHealth(int ammount);

char get_behavior(int y, int x, bool &block_movement,
                  std::string &behavior_name, char side = ' ');

void spawn_spiketop(int count);

#endif
