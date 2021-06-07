#include "lookuptable.h"

class Console
{
	public: 
		Console(const Console&) = delete;
		static Console& Get()
		{
			static Console instance;
			return instance;
		}
		static std::string GetCharacters(){return Get().i_GetCharacters();}
		static bool GetState(){return Get().i_GetState();}
		static int Update(){return Get().i_Update();}
		static void Trigger(){return Get().i_Trigger();}
		static void GetInputs(){return Get().i_GetInputs();}
		static void SendRequest(){return Get().i_SendRequest();}	
		static char KeyToChar(SDL_Event p_event){return Get().i_KeyToChar(p_event);}
		static std::string GetFirstWord(std::string str){return Get().i_GetFirstWord(str);}
		static std::string DelFirstWord(std::string str){return Get().i_DelFirstWord(str);}

	private:
		Console(){}
		int i_Update()
		{
			Console::Trigger();
			if(m_enabled == false)
				return 0;
			if(m_enabled == true)
			{
				Console::GetInputs();
			}
			return 1;
		}
		void i_Trigger()
		{
			if(m_char == ';' && !m_enabled)
			{
				m_char = NULL;
				m_enabled = true;
			}else 
				if(m_char == ';' && m_enabled)
				{
					m_char = NULL;
					m_enabled = false;
				}
		}
		bool i_GetState()
		{
			return m_enabled;
		}
		void i_GetInputs()
		{		
			if(m_char == '\r')
				m_characters = m_lastcharacters;
			if(m_characters != "" && m_char == '\b')
			{
				m_characters.pop_back();
				m_char = 0;
			}	
			if(m_char != 0 && m_char != '\n' && m_char != '\b' && m_char != '\r' && m_char != ';')
			{
				m_characters.push_back(m_char);
				m_char = 0;
			}
			if(m_characters != "" && m_char == '\n')
			{
				m_lastcharacters = m_characters;
				Console::SendRequest();
				m_characters = "";
				m_enabled = false;
			}
		}
		std::string i_GetCharacters()
		{
			return m_characters;
		}
		void i_SendRequest()
		{
			std::string function;
			std::string argument;

			function = Console::GetFirstWord(m_characters);
			m_characters = Console::DelFirstWord(m_characters);

			argument = m_characters; 

			LookupTable::CallFunction(function, argument);
		}
		std::string i_GetFirstWord(std::string str)
		{
			std::string word = "";
			for(char i: str)
			{
				if(i == ' ')
					return word;
				word += i;
			}
			return "";
		}
		std::string i_DelFirstWord(std::string str)
		{
			for(char i: str)
			{	
				if(i == ' '){
					str.erase(0, str.find(i) + 1);
					
					std::cout << i << std::endl;
					return str;
				}
			}
			return "";
		}
	private:
		bool m_enabled;
		char m_char;
		std::string m_characters;
		std::string m_lastcharacters;
	private:
		char i_KeyToChar(SDL_Event p_event)
		{
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_a && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'A';
						return 'A';
					}
					m_char = 'a';
					return 'a';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_z && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'Z';
						return 'Z';
					}
					m_char = 'z';
					return 'z';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_e && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'E';
						return 'E';
					}
					m_char = 'e';
					return 'e';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_r && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'R';
						return 'R';
					}
					m_char = 'r';
					return 'r';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_t && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'T';
						return 'T';
					}
					m_char = 't';
					return 't';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_y && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'Y';
						return 'Y';
					}
					m_char = 'y';
					return 'y';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_u && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'U';
						return 'U';
					}
					m_char = 'u';
					return 'u';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_i && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'I';
						return 'I';
					}
					m_char = 'i';
					return 'i';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_o && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'O';
						return 'O';
					}
					m_char = 'o';
					return 'o';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_p && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'P';
						return 'P';
					}
					m_char = 'p';
					return 'p';
				}
			}
		if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_q && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'Q';
						return 'Q';
					}
					m_char = 'q';
					return 'q';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_s && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'S';
						return 'S';
					}
					m_char = 's';
					return 's';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_d && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'D';
						return 'D';
					}
					m_char = 'd';
					return 'd';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_f && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'F';
						return 'F';
					}
					m_char = 'f';
					return 'f';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_g && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'G';
						return 'G';
					}
					m_char = 'g';
					return 'g';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_h && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'H';
						return 'H';
					}
					m_char = 'h';
					return 'h';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_j && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'J';
						return 'J';
					}
					m_char = 'j';
					return 'j';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_k && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'K';
						return 'K';
					}
					m_char = 'k';
					return 'k';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_l && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'L';
						return 'L';
					}
					m_char = 'l';
					return 'l';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_m && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'M';
						return 'M';
					}
					m_char = 'm';
					return 'm';
				}
			}

			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_w && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'W';
						return 'W';
					}
					m_char = 'w';
					return 'w';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_x && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'X';
						return 'X';
					}
					m_char = 'x';
					return 'x';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_c && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'C';
						return 'C';
					}
					m_char = 'c';
					return 'c';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_v && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'V';
						return 'V';
					}
					m_char = 'v';
					return 'v';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_b && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'B';
						return 'B';
					}
					m_char = 'b';
					return 'b';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_n && !p_event.key.repeat)
				{
					SDL_Keymod modstates = SDL_GetModState();
					if(modstates & KMOD_SHIFT)
					{
						m_char = 'N';
						return 'N';
					}
					m_char = 'n';
					return 'n';
				}
			}

			if(p_event.type == SDL_KEYDOWN)
			{
				if((p_event.key.keysym.sym == SDLK_8 || p_event.key.keysym.sym == SDLK_UNDERSCORE) && !p_event.key.repeat)
				{
					m_char = '_';
					return '_';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_PERIOD && !p_event.key.repeat)
				{
					m_char = '.';
					return '.';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_SEMICOLON && !p_event.key.repeat)
				{
					m_char = ';';
					return ';';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_BACKSPACE && !p_event.key.repeat)
				{
					m_char = '\b';
					return '\b';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_RETURN && !p_event.key.repeat)
				{	
					m_char = '\n';
					return '\n';
				}
			}
			if(p_event.type == SDL_KEYDOWN)
			{
				if(p_event.key.keysym.sym == SDLK_SPACE && !p_event.key.repeat)
				{	
					m_char = ' ';
					return ' ';
				}
			}
			if(p_event.type == SDL_KEYDOWN && m_enabled)
			{
				if(p_event.key.keysym.sym == SDLK_UP && !p_event.key.repeat)
				{	
					m_char = '\r';
					return '\r';
				}
			}

			return -1;
		}		
};
