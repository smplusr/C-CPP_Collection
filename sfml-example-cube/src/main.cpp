// Loading required dependencies
#include <../include/SFML/Window.hpp>
#include <../include/SFML/OpenGL.hpp>
#include <../include/GL/glu.h>

#include <iostream>
#include <cmath>

// Loading Singleton classes (modules)
#include "modules/display.h"
#include "modules/camera.h"

// Loading Cube header and class
#include "assets/model.h"
Cube cube;
Plane plane;

int main()
{
	// Create SFML window from Singleton template
	sf::Window window = Display::CreateWindow();
	window.setActive();
	Display::GLSettings();

	// Creating the events system
	sf::Event event;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
		}
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Camera::Translate();
		Camera::Rotate();
		Camera::Update();
		Camera::Log();

		// Clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		// Draw the geometries
		cube.update();
		plane.draw();

		// Update the display
		window.display();
	}

	return 0;
}
