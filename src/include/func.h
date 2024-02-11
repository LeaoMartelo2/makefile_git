#ifndef FUNC_H
#define FUNC_H

#include <string>

void ConsoleMessage(std::string message, bool displayHeader);

void CoordDebugMessage(std::string message, bool showDebug, int y, int x);

void GenDungeon(char map[][81], int rows, int cols);

void clearMap(char map[][81]);

void movePlayer(char map[][81], int &y, int &x, char input);

void mapBorder(char map[][81]);

#endif
