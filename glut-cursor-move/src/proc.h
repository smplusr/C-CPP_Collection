#pragma once

#ifndef PROC_H
#define PROC_H

#define PROC_FUNC()\
	if(spe_buffer[GLUT_KEY_UP])\
		mouse_y-=MOUSE_SPEED;\
	if(spe_buffer[GLUT_KEY_DOWN])\
		mouse_y+=MOUSE_SPEED;\
	if(spe_buffer[GLUT_KEY_LEFT])\
		mouse_x-=MOUSE_SPEED;\
	if(spe_buffer[GLUT_KEY_RIGHT])\
		mouse_x+=MOUSE_SPEED;\
	glutWarpPointer(mouse_x,mouse_y);

#endif
