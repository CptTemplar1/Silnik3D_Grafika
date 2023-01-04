#include <gl/glut.h>
#include <gl/freeglut.h>
#include <iostream>
#include "Engine.h"

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	Engine* engine = new Engine(900, 900);
	engine->setBackGroundColor({ 0, 0, 0, 1 });
	engine->mainLoop();
    return(0);
}