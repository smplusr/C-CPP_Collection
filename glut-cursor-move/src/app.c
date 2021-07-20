#include"app.h"
#include"proc.h"

bool key_buffer[256],spe_buffer[256];
int mouse_x,mouse_y;

void keyboard_down(unsigned char key,int x,int y){key_buffer[key]=1;}
void keyboard_up(unsigned char key,int x,int y){key_buffer[key]=0;}
void special_down(int key,int x,int y){spe_buffer[key]=1;}
void special_up(int key,int x,int y){spe_buffer[key]=0;}

void passive_mouse(int x,int y){mouse_x=x,mouse_y=y;}

void display(){glutPostRedisplay();}

void update(int tick){
	PROC_FUNC();
	glutTimerFunc(1000/60,update,tick);
}

void createWindow(){
	glutCreateWindow("window");
}

int loadGlut(int argc,char **argv){
	glutInit(&argc,argv);
	if(!glutGet(GLUT_INIT_STATE))
		return FAILED_TO_INITIALISE_GLUT;
	return NO_ERROR;
}

void setGlutParameters(){
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard_down);
	glutKeyboardUpFunc(keyboard_up);
	glutSpecialFunc(special_down);
	glutSpecialUpFunc(special_up);

	glutPassiveMotionFunc(passive_mouse);

	glutTimerFunc(100,update,0);

	glutMainLoop();
}
