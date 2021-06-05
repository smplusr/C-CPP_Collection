class Display
{
	public:
		Display(const Display&) = delete;
		static Display& Get()
		{
			static Display instance;
			return instance;
		}
		static sf::ContextSettings ContextSettings(){return Get().i_ContextSettings();}
		static void GLSettings(){return Get().i_GLSettings();}
		static sf::Window CreateWindow(){return Get().i_CreateWindow();}
		static sf::RenderWindow CreateRenderWindow(){return Get().i_CreateRenderWindow();}

	private:
		Display(){}	
		sf::ContextSettings i_ContextSettings()
		{
			m_settings.depthBits = s_depthBits;
			m_settings.stencilBits = s_stencilBits;
			m_settings.antialiasingLevel = s_antialiasingLevel;
			return m_settings;
		}
		sf::RenderWindow i_CreateRenderWindow()
		{
			return sf::RenderWindow(
					sf::VideoMode(s_width, s_height, s_bitsPerPixel), 
					s_title, 
					sf::Style::Close, 
					ContextSettings()
					);
		}
		sf::Window i_CreateWindow()
		{
			return sf::Window(
					sf::VideoMode(s_width, s_height, s_bitsPerPixel), 
					s_title, 
					sf::Style::Close, 
					ContextSettings()
					);
		}
		void i_GLSettings()
		{
			glClearDepth(s_clearDepth);
			glClearColor(s_clearColorRed, s_clearColorGreen, s_clearColorBlue, s_clearColorTransparency);
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(s_fov, s_aspect, s_nearClipPlane, s_farClipPlane);
		
		}
	private:
		// Private shared settings
		sf::ContextSettings m_settings;
	public:
		// Context Settings
		int s_depthBits = 24;
		int s_stencilBits = 8;
		int s_antialiasingLevel = 2;
		// Window Settings
		int s_width = 512;
		int s_height = 512;
		int s_bitsPerPixel = 32;
		char s_title[6] = {'w', 'i', 'n', 'd', 'o', 'w'};
		// OpenGL Settings
		float s_clearDepth = 1.f;
		float s_clearColorRed = 0.07f;	
		float s_clearColorGreen = 0.09f;
		float s_clearColorBlue = 0.11f;	
		float s_clearColorTransparency = 1.f;
		float s_fov = 75.f;
		float s_aspect = 1.f;
		float s_nearClipPlane = 0.1f;
		float s_farClipPlane = 500.f;
};
