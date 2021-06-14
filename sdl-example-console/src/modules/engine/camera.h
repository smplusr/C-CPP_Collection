#ifndef CAMERA_H
#define CAMERA_H

#include <../include/SDL2/SDL.h>

class Camera
{
	public:
		Camera(const Camera&) = delete;
		static Camera& Get()
		{
			static Camera instance;
			return instance;
		}
		static void Translate(const Uint8* p_keyState){return Get().i_Translate(p_keyState);}
		static void Rotate(const Uint8* p_keyState){return Get().i_Rotate(p_keyState);}
		static void Update(){return Get().i_Update();}
		static void Log(){return Get().i_Log();}
	private:
		Camera(){}
		void i_Translate(const Uint8* p_keyState)
		{			
			if(p_keyState[SDL_SCANCODE_W])
			{
				m_positionX += m_directionX * m_moveSpeed;
				m_positionZ += m_directionZ * m_moveSpeed;
			}

			if(p_keyState[SDL_SCANCODE_S])
			{
				m_positionX -= m_directionX * m_moveSpeed;
				m_positionZ -= m_directionZ * m_moveSpeed;
			}

			if(p_keyState[SDL_SCANCODE_A])
			{
				m_positionX -= (sin(m_angleX + M_PI/2)) * m_moveSpeed;
				m_positionZ -= (-cos(m_angleX + M_PI/2)) * m_moveSpeed;
			}
			
			if(p_keyState[SDL_SCANCODE_D])
			{	
				m_positionX += (sin(m_angleX + M_PI/2)) * m_moveSpeed;
				m_positionZ += (-cos(m_angleX + M_PI/2)) * m_moveSpeed;
			}

			if(p_keyState[SDL_SCANCODE_SPACE])
				m_positionY += m_moveSpeed;

			if(p_keyState[SDL_SCANCODE_LALT])
				m_positionY -= m_moveSpeed;

			if(p_keyState[SDL_SCANCODE_LSHIFT])
			{
				m_moveSpeed = .06f;
			}else{
				m_moveSpeed = .02f;
			}
		}
		void i_Rotate(const Uint8* p_keyState)
		{
			if(p_keyState[SDL_SCANCODE_UP])
			{	
				if(m_angleY < m_maxY)
				{
					m_angleY += m_rotSpeed;
					m_directionY = tan(m_angleY);
				}
			}

			if(p_keyState[SDL_SCANCODE_DOWN])
			{
				if(m_angleY > m_minY)
				{
					m_angleY -= m_rotSpeed;
					m_directionY = tan(m_angleY);
				}
			}

			if(p_keyState[SDL_SCANCODE_LEFT])
			{
				m_angleX -= m_rotSpeed;
				m_directionX = sin(m_angleX);
				m_directionZ = -cos(m_angleX);
			}
			
			if(p_keyState[SDL_SCANCODE_RIGHT])
			{	
				m_angleX += m_rotSpeed;
				m_directionX = sin(m_angleX);
				m_directionZ = -cos(m_angleX);
			}
		}
		void i_Update()
		{
			gluLookAt(m_positionX, 
					m_positionY, 
					m_positionZ,
					m_positionX + m_directionX,
					m_positionY + m_directionY,
					m_positionZ + m_directionZ,
					0, 1, 0);
		}
		void i_Log(){}
	private:
		float m_moveSpeed;
		float m_rotSpeed = .02f;
		float m_angleX;
		float m_angleY;
		float m_maxY = 1.5f;
		float m_minY = -1.5f;
		float m_directionX;
		float m_directionY;
		float m_directionZ = -.5f;
		float m_positionX;
		float m_positionY;
		float m_positionZ = 2.f;
};

#endif
