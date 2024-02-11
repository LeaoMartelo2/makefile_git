#ifndef FUNC_H
#define FUNC_H

void GenRandomRoom(char map[][81], int rows, int cols);

void clearMap(char map[][81]);

void movePlayer(char map[][81], int &y, int &x, char input);

void mapBorder(char map[][81]);

#endif
