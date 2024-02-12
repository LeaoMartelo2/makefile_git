#ifndef FUNC_H
#define FUNC_H

void GenRandomRoom(char map[][81]);

void clearMap(char map[][81]);

void movePlayer(int &y, int &x, char input);

void mapBorder(char map[][81]);

void debug_printPlayerXY(int &playerY, int &playerX);

void debug_printLastInput(char input);

void debug_regenMap(char input, int &playerY, int &playerX);

void printPlayer(int &y, int &x, char player);

#endif
