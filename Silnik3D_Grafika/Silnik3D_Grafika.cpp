
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/glm.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "Engine.h"

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	Engine* engine = new Engine(900, 900);
	engine->setBackGroundColor({ 0, 0, 0, 1 });
	//engine->toggleFullScreen;
	engine->mainLoop();

	return 0;
}

