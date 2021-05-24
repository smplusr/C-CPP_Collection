#include "modules/link.h"

Cube cube;
void update()
{
	cube.update();
}

int main()
{
	System::Init();
	Display::Init();
	Display::CreateWindow();
	Display::Refresh();
}
