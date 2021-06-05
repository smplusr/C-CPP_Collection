void nullCommand(std::string p_argument){}

void PrintToConsole(std::string p_argument){std::cout << p_argument << std::endl;}

void glFunction(std::string p_argument)
{	
	if(p_argument.find("glPolygonMode") != std::string::npos)
	{
		if(p_argument.find("GL_LINE") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		if(p_argument.find("GL_POINT") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		if(p_argument.find("GL_FILL") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
void gluFunction(std::string p_argument)
{	
	if(p_argument.find("gluPerspective") != std::string::npos)
	{
		float fov = 75.f;
		if(p_argument.find("reset") != std::string::npos)
			gluPerspective(75.f, 1.f, .1f, 500.f);
		if(p_argument.find("increase") != std::string::npos)
		{
			fov += 10.f;
			gluPerspective(fov, 1.f, .1f, 500.f);
		}	
		if(p_argument.find("decrease") != std::string::npos)
		{
			fov -= 10.f;
			gluPerspective(fov, 1.f, .1f, 500.f);
		}
	}
}
