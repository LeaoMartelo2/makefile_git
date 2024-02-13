#ifndef DEBUG_H
#define DEBUG_H

void debug_printPlayerXY(int &playerY, int &playerX);

void debug_printLastInput(char input);

void debug_regenMap(char input, int &playerY, int &playerX);

void debug_header();

void debug_log(const char *message);

void debug_log_colision(const char *position, const char *behavior);

#endif // !DEBUG_H
