#include "screen.h"

Cube cube;

void _update()
{
	extern Cube cube;
	cube.update();	
}
int main()
{
	_display();
}
