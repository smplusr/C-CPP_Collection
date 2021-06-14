#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>

#include "../include/SDL2/SDL_opengl.h"
#include "../include/SDL2/SDL.h"

#include "../include/GL/glu.h"

#include "../src/modules/misc/gameobject.h"

void nullCommand(std::string p_argument);
void printToConsole(std::string p_argument);
void glFunction(std::string p_argument);
void gluFunction(std::string p_argument);
void objFunction(std::string p_argument);

#endif
