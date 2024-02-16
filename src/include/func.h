#ifndef FUNC_H
#define FUNC_H

#include <string>

#define BEHAVIOR_SOLID_WALL '#'
#define BEHAVIOR_COLLECTIBLE_COIN '$'
#define BEHAVIOR_DAMAGE_SOLID 'D'
#define BEHAVIOR_SPIKETOP_SOLID '^'
#define BEHAVIOR_EMPTY ' '
#define BEHAVIOR_UNKNOWN 'U'
#define BEHAVIOR_PORTAL_LEFT '['
#define BEHAVIOR_PORTAL_RIGHT ']'
#define BEHAVIOR_PORTAL_TOP '('
#define BEHAVIOR_PORTAL_BOTTOM ')'

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

void print_minimap(int minimap[][3]);

void buffer_to_screen(char buffer[][81]);

#endif
