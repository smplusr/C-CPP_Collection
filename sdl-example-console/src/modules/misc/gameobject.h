#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <memory>

class GameObject
{
	public:
		virtual void Update(){}
		virtual void SetPos(float p_x, float p_y, float p_z)
		{
			m_x = p_x;
			m_y = p_y;
			m_z = p_z;
		}
		virtual float GetPos(char m_axes){return 0;}	
	private:
		static std::vector<GameObject*> objectArray;
	public:
		GameObject()
		{
			objectArray.push_back(this);
		}
		static std::vector<GameObject*> getAllObjects()
		{
			return objectArray;
		}
	private:
		float m_x;
		float m_y;
		float m_z;
};

class Factory
{
	public:
		Factory(const Factory&) = delete;
		static Factory& Get()
		{
			static Factory instance;
			return instance;
		}
	public:
		Factory(){}
	public:
		static std::shared_ptr<GameObject> CreateInstance(std::string name);
};

#endif
