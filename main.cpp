#include "main.h"
#include "mygl.h"
#include "mygl.cpp"

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	DrawFunc = MyGlDraw;	

	glutMainLoop();

	return 0;
}

