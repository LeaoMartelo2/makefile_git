#ifndef FUNC_H
#define FUNC_H

void GenRandomRoom(char map[][81]);

void clearMap(char map[][81]);

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void printPlayer(int &y, int &x, char player);

#endif
