#pragma once

#include"pch.h"
#include"errdef.h"

#ifndef APP_H
#define APP_H

#define MOUSE_SPEED 5

extern bool key_buffer[256],spe_buffer[256];
extern int mouse_x,mouse_y;

void keyboard_down(unsigned char key,int x,int y);
void keyboard_up(unsigned char key,int x,int y);
void special_down(int key,int x,int y);
void special_up(int key,int x,int y);

void passive_mouse(int x,int y);

void display();

void update(int v);

void createWindow();
int loadGlut(int argc,char **argv);
void setGlutParameters();

#endif
