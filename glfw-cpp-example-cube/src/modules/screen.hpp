/*#ifndef MAIN_CPP
#define MAIN_CPP
#include "../main.cpp"
#endif*/

void update();

class Display
{
	public:
		Display(const Display&) = delete;
		static Display& Get()
		{
			static Display instance;
			return instance;
		}
		static int Init(){return Get().InitInternal();}
		static int CreateWindow(){return Get().CreateWindowInternal();}
		static void Clear(){return Get().ClearInternal();}
		static void Refresh(){return Get().RefreshInternal();}
	private:
		Display(){}
		GLFWwindow* m_window;
		int InitInternal()
		{
			if(!glfwInit())
			{
				std::cout << "[ERROR]: GLFW could not be initialized" << std::endl;
				return -1;
			}
			else
			{
				std::cout << "[INFO]: GLFW started" << std::endl;	
			}
			return 0;
		}
		int CreateWindowInternal()
		{
			m_window = glfwCreateWindow(512, 512, "window", NULL, NULL);
			if(!m_window)
			{
				std::cout << "[ERROR]: GLFW could not create a window" << std::endl;
				glfwTerminate();
				return -1;
			}	
			glfwMakeContextCurrent(m_window);
			std::cout << "[INFO]: Running on OpenGL version: " << "OpenGL " << glGetString(GL_VERSION) << std::endl;
			glEnable(GL_DEPTH_TEST);
			return 0;
		}
		void ClearInternal(){
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();
		}
		void RefreshInternal(){
			while(!glfwWindowShouldClose(m_window)){
				Clear();
				update();	
				glfwSwapBuffers(m_window);
			}
		}
		
};
