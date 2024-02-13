#ifndef FUNC_H
#define FUNC_H

#define BEHAVIOR_SOLID_WALL '#'
#define BEHAVIOR_COLLECTIBLE_COIN '$'
#define BEHAVIOR_DAMAGE_SOLID 'D'
#define BEHAVIOR_EMPTY ' '
#define BEHAVIOR_UNKNOWN 'U'

void GenRandomRoom(char map[][81]);

void clearMap();

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void printPlayer(int &y, int &x, char player);

void add_obj(int y, int x, char visual, char behavior = ' ',
             int color_attr = 0);

void roomPopulate_Coins();

void spawn_damage_solid(int count);

void modifyCoins(int ammount);

void modifyHealth(int ammount);

#endif
