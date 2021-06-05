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
		static char KeyToChar(sf::Event event){return Get().i_KeyToChar(event);}
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
			if(m_char == '/' && m_enabled == false)
				m_enabled = true;
			if(m_char == '/' && m_enabled == true)
				m_enabled == false;
		}
		bool i_GetState()
		{
			return m_enabled;
		}
		void i_GetInputs()
		{		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				m_characters = m_lastcharacters;
			if(m_characters != m_emptystring && m_char == '\b')
			{
				m_characters.pop_back();
				m_char = 0;
			}	
			if(m_char != 0 && m_char != '\n' && m_char != '\b' && m_char != '/')
			{
				m_characters.push_back(m_char);
				m_char = 0;
			}
			if(m_characters != m_emptystring && m_char == '\n')
			{
				m_lastcharacters = m_characters;
				Console::SendRequest();
				m_characters = m_emptystring;
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
			for(auto i: str)
			{
				if(i == ' ')
					return word;
				word += i;
			}
		}
		std::string i_DelFirstWord(std::string str)
		{
			for(auto i: str)
			{	
				if(i == ' '){
					str.erase(0, str.find(i) + 1);
					
					std::cout << i << std::endl;
					return str;
				}
			}
		}

	private:
		bool m_enabled;
		char m_char;
		std::string m_characters;
		std::string m_lastcharacters;
		std::string m_emptystring;
		sf::Text m_text;
	private:
		char i_KeyToChar(sf::Event event)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if(event.type == sf::Event::KeyPressed)
				{
					switch(event.key.code)
					{	
						case sf::Keyboard::A:
							m_char = 'A';
							return 'A';
							break;
						case sf::Keyboard::Z:
							m_char = 'Z';
							return 'Z';
							break;
						case sf::Keyboard::E:
							m_char = 'E';
							return 'E';
							break;
						case sf::Keyboard::R:
							m_char = 'R';
							return 'R';
							break;
						case sf::Keyboard::T:
							m_char = 'T';
							return 'T';
							break;
						case sf::Keyboard::Y:
							m_char = 'Y';
							return 'Y';
							break;
						case sf::Keyboard::U:
							m_char = 'U';
							return 'U';
							break;
						case sf::Keyboard::I:
							m_char = 'I';
							return 'I';
							break;
						case sf::Keyboard::O:
							m_char = 'O';
							return 'O';
							break;
						case sf::Keyboard::P:
							m_char = 'P';
							return 'P';
							break;
						case sf::Keyboard::Q:
							m_char = 'Q';
							return 'Q';
							break;
						case sf::Keyboard::S:
							m_char = 'S';
							return 'S';
							break;
						case sf::Keyboard::D:
							m_char = 'D';
							return 'D';
							break;
						case sf::Keyboard::F:
							m_char = 'F';
							return 'F';
							break;
						case sf::Keyboard::G:
							m_char = 'G';
							return 'G';
							break;
						case sf::Keyboard::H:
							m_char = 'H';
							return 'H';
							break;
						case sf::Keyboard::J:
							m_char = 'J';
							return 'J';
							break;
						case sf::Keyboard::K:
							m_char = 'K';
							return 'K';
							break;
						case sf::Keyboard::L:
							m_char = 'L';
							return 'L';
							break;
						case sf::Keyboard::M:
							m_char = 'M';
							return 'M';
							break;
						case sf::Keyboard::W:
							m_char = 'W';
							return 'W';
							break;
						case sf::Keyboard::X:
							m_char = 'X';
							return 'X';
							break;
						case sf::Keyboard::C:
							m_char = 'C';
							return 'C';
							break;
						case sf::Keyboard::V:
							m_char = 'V';
							return 'V';
							break;
						case sf::Keyboard::B:
							m_char = 'B';
							return 'B';
							break;
						case sf::Keyboard::N:
							m_char = 'N';
							return 'N';
							break;	
						default:
							break;
					}
				}
			}else{
				if(event.type == sf::Event::KeyPressed)
				{
					switch(event.key.code)
					{	
						case sf::Keyboard::A:
							m_char = 'a';
							return 'a';
							break;
						case sf::Keyboard::Z:
							m_char = 'z';
							return 'z';
							break;
						case sf::Keyboard::E:
							m_char = 'e';
							return 'e';
							break;
						case sf::Keyboard::R:
							m_char = 'r';
							return 'r';
							break;
						case sf::Keyboard::T:
							m_char = 't';
							return 't';
							break;
						case sf::Keyboard::Y:
							m_char = 'y';
							return 'y';
							break;
						case sf::Keyboard::U:
							m_char = 'u';
							return 'u';
							break;
						case sf::Keyboard::I:
							m_char = 'i';
							return 'i';
							break;
						case sf::Keyboard::O:
							m_char = 'o';
							return 'o';
							break;
						case sf::Keyboard::P:
							m_char = 'p';
							return 'p';
							break;
						case sf::Keyboard::Q:
							m_char = 'q';
							return 'q';
							break;
						case sf::Keyboard::S:
							m_char = 's';
							return 's';
							break;
						case sf::Keyboard::D:
							m_char = 'd';
							return 'd';
							break;
						case sf::Keyboard::F:
							m_char = 'f';
							return 'f';
							break;
						case sf::Keyboard::G:
							m_char = 'g';
							return 'g';
							break;
						case sf::Keyboard::H:
							m_char = 'h';
							return 'h';
							break;
						case sf::Keyboard::J:
							m_char = 'j';
							return 'j';
							break;
						case sf::Keyboard::K:
							m_char = 'k';
							return 'k';
							break;
						case sf::Keyboard::L:
							m_char = 'l';
							return 'l';
							break;
						case sf::Keyboard::M:
							m_char = 'm';
							return 'm';
							break;
						case sf::Keyboard::W:
							m_char = 'w';
							return 'w';
							break;
						case sf::Keyboard::X:
							m_char = 'x';
							return 'x';
							break;
						case sf::Keyboard::C:
							m_char = 'c';
							return 'c';
							break;
						case sf::Keyboard::V:
							m_char = 'v';
							return 'v';
							break;
						case sf::Keyboard::B:
							m_char = 'b';
							return 'b';
							break;
						case sf::Keyboard::N:
							m_char = 'n';
							return 'n';
							break;	
	
						case sf::Keyboard::Space:
							m_char = ' ';
							return ' ';
							break;
						case sf::Keyboard::Return:
							m_char = '\n';
							return '\n';
							break;
						case::sf::Keyboard::Backspace:
							m_char = '\b';
							return '\b';
							break;
						case sf::Keyboard::Period:
							m_char = '.';
							return '.';
							break;		
						case sf::Keyboard::Hyphen:
							m_char = '_';
							return '_';
							break;
						case sf::Keyboard::Slash:
							m_char = '/';
							return '/';
							break;	
						default:
							break;
					}
				}
			}
			return 0;
		}
};
