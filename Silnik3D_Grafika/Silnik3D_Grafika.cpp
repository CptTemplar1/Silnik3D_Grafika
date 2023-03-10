
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/glm.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "Engine.h"

/** \brief Funkcja main
 *
 * Glowna funkcja programu tworzaca silnik i uruchamiajaca glowna petle.
 *
 * \param[in] argc liczba argumentow
 * \param[in] argv wskaznik na tablice argumentow
 *
 */
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	Engine* engine = new Engine(1600, 900);
	engine->setBackGroundColor({ 0, 0, 0, 0 });
	//engine->toggleFullScreen;
	engine->mainLoop();

	return 0;
}

