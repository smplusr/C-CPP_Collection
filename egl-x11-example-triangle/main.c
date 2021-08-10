/* gcc main.c -lX11 -lEGL -lGESv2 -o a.out */

#include"display.h"
#include"triangle.h"

int main(int argc, char *argv[])
{
	const unsigned int width = 640,height = 480;
	struct display *display;
	struct window *window;

	display=display_open();
	window=window_create(display, argv[0], 0, 0, width, height);

	window_show(window);
	DrawTriangle(window);
	sleep(10);

	window_close(window);
	display_close(display);
	return 0;
}
