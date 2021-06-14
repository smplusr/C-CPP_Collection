#ifndef DISPLAY_H
#define DISPLAY_H

#include <../include/SDL2/SDL_opengl.h>
#include <../include/SDL2/SDL.h>
#include <../include/GL/glu.h>

class Display
{
	public:
		Display(const Display&) = delete;
		static Display& Get()
		{
			static Display instance;
			return instance;
		}
		static SDL_Window* CreateWindow(){return Get().i_CreateWindow();}
		static SDL_Renderer* CreateRenderer(SDL_Window* p_window){return Get().i_CreateRenderer(p_window);}
		static void GLSettings(){return Get().i_GLSettings();}
		static void GLAttributes(){return Get().i_GLAttributes();}
		static int GetWidth(){return Get().i_GetWidth();}
		static int GetHeight(){return Get().i_GetHeight();}
	private:
		Display(){}
		SDL_Window* i_CreateWindow()
		{
			return SDL_CreateWindow(m_title,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					m_width,
					m_height,
					SDL_WINDOW_SHOWN |
					SDL_WINDOW_OPENGL);
		}
		SDL_Renderer* i_CreateRenderer(SDL_Window* p_window)
		{
			return SDL_CreateRenderer(p_window, 
					-1, 
					SDL_RENDERER_ACCELERATED);
		}
		void i_GLSettings()
		{
			glClearDepth(m_clearDepth);
			glClearColor(m_clearColorRed, 
					m_clearColorGreen,
					m_clearColorBlue, 
					m_clearColorAlpha);
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(m_fov, 
					m_aspect, 
					m_nearClipPlane, 
					m_farClipPlane);
		}
		void i_GLAttributes()
		{
			SDL_GL_SetSwapInterval(0);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		}
		int i_GetWidth(){return m_width;}
		int i_GetHeight(){return m_height;}
	private:
		// Window Settings
		char m_title[6] = {'w', 'i', 'n', 'd', 'o', 'w'};
		int m_width = 520;
		int m_height = 520;
		// OpenGL Settings
		float m_clearDepth = 1.f;
		float m_clearColorRed = .07f;
		float m_clearColorGreen = .09f;
		float m_clearColorBlue = .11f;
		float m_clearColorAlpha = 1.f;
		float m_fov = 75.f;
		float m_aspect = 1.f;
		float m_nearClipPlane = .1f;
		float m_farClipPlane = 500.f;
};

#endif
