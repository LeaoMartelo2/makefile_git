#ifndef ROOMS_H
#define ROOMS_H

#include "debug.h"
#include "func.h"
#include <ncurses.h>
#include <string>

void room_Start();

void gen_structure();

void drawName(std::string room_name);

#endif
