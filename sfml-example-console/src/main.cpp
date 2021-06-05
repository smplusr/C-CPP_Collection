// Including the header container
#include "headref.hpp"

// Creating class instances
Cube cube;
Plane plane;

int main()
{
	// Create SFML window from Singleton template
	sf::RenderWindow window = Display::CreateRenderWindow();
	window.setActive();
	Display::GLSettings();
	
	// Creating the events system
	sf::Event event;	
	
	while(true)
	{
		// User inputs
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}

			// Putting key event in a specific character while updated
			Console::KeyToChar(event);
		}

		// Update the Console
		Console::Update();	

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Camera::Translate();
		Camera::Rotate();
		Camera::Update();
		//Camera::Log();

		// Clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		// Draw the geometries
		cube.update();
		plane.draw();	


		// Save OpenGL State
		window.pushGLStates();

		sf::Font font;
		font.loadFromFile("../src/assets/font/arial.ttf");
		sf::Text text;
		if(Console::GetState() == true)
		{
			text.setString(Console::GetCharacters().insert(0, "> "));
			text.setFont(font);
			text.setCharacterSize(12);
		}
		text.move(0.f, 512 - 12 * 1.5);

		// Draw using SFML's Graphic module
		window.draw(text);


		// Restore OpenGL State
		window.popGLStates();


		window.display();
	}

	return 0;
}
