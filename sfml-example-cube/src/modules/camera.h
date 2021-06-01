class Camera
{
	public:
		Camera(const Camera&) = delete;
		static Camera& Get()
		{
			static Camera instance;
			return instance;
		}
		static void Translate(){return Get().i_Translate();}
		static void Rotate(){return Get().i_Rotate();}
		static void Update(){return Get().i_Update();}
		static void Log(){return Get().i_Log();}
	private:
		Camera(){}
		void i_Translate()
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				s_moveSpeed = .06;
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				s_moveSpeed = .02;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				s_positionX -= (sin(s_angleX + M_PI/2)) * s_moveSpeed;
				s_positionZ -= (-cos(s_angleX + M_PI/2)) * s_moveSpeed;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				s_positionX += (sin(s_angleX + M_PI/2)) * s_moveSpeed;
				s_positionZ += (-cos(s_angleX + M_PI/2)) * s_moveSpeed;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				s_positionX += s_directionX * s_moveSpeed;
				s_positionY += s_directionY * s_moveSpeed;
				s_positionZ += s_directionZ * s_moveSpeed;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				s_positionX -= s_directionX * s_moveSpeed;
				s_positionY -= s_directionY * s_moveSpeed;
				s_positionZ -= s_directionZ * s_moveSpeed;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				s_positionY += s_moveSpeed;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				s_positionY -= s_moveSpeed;
		}
		void i_Rotate()
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				s_angleY += s_rotSpeed;
				s_directionY = tan(s_angleY);
			}	
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				s_angleY -= s_rotSpeed;
				s_directionY = tan(s_angleY);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				s_angleX -= s_rotSpeed;
				s_directionX = sin(s_angleX);
				s_directionZ = -cos(s_angleX);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				s_angleX += s_rotSpeed;
				s_directionX = sin(s_angleX);
				s_directionZ = -cos(s_angleX);
			}

		}
		void i_Update()
		{
			gluLookAt(
					s_positionX, 
					s_positionY, 
					s_positionZ,
					s_positionX + s_directionX, 
					s_positionY + s_directionY, 
					s_positionZ + s_directionZ,
					0, 1, 0
				);		
		}
		void i_Log()
		{
			std::cout << "Angle X: " << s_angleX << std::endl;	
			std::cout << "Angle Y: " << s_angleY << std::endl;

			std::cout << "\n" << std::endl;

			std::cout << "Direction X: " << s_directionX << std::endl;
			std::cout << "Direction Y: " << s_directionY << std::endl;
			std::cout << "Direction Z: " << s_directionZ << std::endl;
		
			std::cout << "\n" << std::endl;

			std::cout << "Position X: " << s_positionX << std::endl;
			std::cout << "Position Y: " << s_positionY << std::endl;
			std::cout << "Position Z: " << s_positionZ << std::endl;

			std::cout << "\n" << std::endl;
			std::cout << "------------------------------------" << std::endl;	
			std::cout << "\n" << std::endl;
		}
	public:
		float s_moveSpeed = .02;
		float s_rotSpeed = .02;
		float s_angleX;
		float s_angleY;
		float s_directionX;
		float s_directionY = -5.;
		float s_directionZ;
		float s_positionX;
		float s_positionY = 1.;
		float s_positionZ = 2.;
};
