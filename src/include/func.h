#ifndef FUNC_H
#define FUNC_H

#define BEHAVIOR_SOLID_WALL '#'
#define BEHAVIOR_EMPTY ' '

void GenRandomRoom(char map[][81]);

void clearMap(char map[][81]);

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void printPlayer(int &y, int &x, char player);

void add_obj(int y, int x, char visual, char behavior = ' ',
             int color_attr = 0);

#endif
