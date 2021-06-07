class ScreenLogger
{
	public:
		ScreenLogger(const ScreenLogger&) = delete;
		static ScreenLogger& Get()
		{
			static ScreenLogger instance;
			return instance;
		}

		static void RenderText(std::string message, 
				SDL_Color color, 
				int x, 
				int y,
				const char* p_font,
				int p_size)
		{
			return Get().i_RenderText(message, 
				color, 
				x, 
				y,
				p_font,
				p_size);
		}
	private:
		ScreenLogger(){}
		void i_RenderText(std::string message,
				SDL_Color color,
				int x,
				int y,
				const char* p_font,
				int p_size)
		{
			TTF_Init();
			
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
	   
			gluOrtho2D(0, 
					Display::GetWidth(), 
					0, 
					Display::GetHeight());

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
	
			glDisable(GL_DEPTH_TEST);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);	
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
			GLuint texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			
			TTF_Font* font = TTF_OpenFont(p_font, p_size);	

			SDL_Surface * sFont = TTF_RenderText_Blended(font, 
				message.c_str(), 
				color);

			glTexParameteri(GL_TEXTURE_2D, 
				GL_TEXTURE_MIN_FILTER, 
				GL_LINEAR);

			glTexParameteri(GL_TEXTURE_2D, 
				GL_TEXTURE_MAG_FILTER, 
				GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 
				0, 
				GL_RGBA, 
				sFont->w, 
				sFont->h, 
				0, 
				GL_BGRA, 
				GL_UNSIGNED_BYTE, 
				sFont->pixels);
	
			glBegin(GL_QUADS);
			{
				glTexCoord2f(0,1); glVertex2f(x, y);
				glTexCoord2f(1,1); glVertex2f(x + sFont->w, y);
				glTexCoord2f(1,0); glVertex2f(x + sFont->w, y + sFont->h);
				glTexCoord2f(0,0); glVertex2f(x, y + sFont->h);
			
			}	
			glEnd();
	
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);	
			glEnable(GL_DEPTH_TEST);
	
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
				
			glDeleteTextures(1, &texture);
			SDL_FreeSurface(sFont);
			TTF_CloseFont(font);

			glPushMatrix();
			glBegin(GL_QUADS);
			glEnd();
			glPopMatrix();
		}
};
