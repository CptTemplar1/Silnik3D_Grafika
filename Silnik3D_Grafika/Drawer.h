#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "../glm/glm.hpp"
#include "../glm/matrix.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
class Drawer
{
public:
	static void drawTriangles(glm::vec3 tab[], glm::vec3 color[], int n = 4);
	static void drawTriangles(glm::vec3 tab[], glm::vec3 color, int n = 4);
	static void drawTrianglesStrip(glm::vec3 tab[], glm::vec3 color[], int n = 4);
	static void drawTrianglesStrip(glm::vec3 tab[], glm::vec3 color, int n = 4);
	static void drawTrianglesFan(glm::vec3 tab[], glm::vec3 color[], int n = 4);
	static void drawTrianglesFan(glm::vec3 tab[], glm::vec3 color, int n = 4);
	static void drawLines(glm::vec3 tab[], glm::vec3 color[], int size, int n);
	static void drawLines(glm::vec3 tab[], glm::vec3 color, int size, int n);
	static void drawLinesLoop(glm::vec3 tab[], glm::vec3 color[], int size, int n = 4);
	static void drawLinesLoop(glm::vec3 tab[], glm::vec3 color, int size, int n = 4);
	static void drawPoints(glm::vec3 tab[], glm::vec3 color[], int size, int n);
	static void drawPoints(glm::vec3 tab[], glm::vec3 color, int size, int n);
	static void drawQuards(glm::vec3 tab[], glm::vec3 color[], int n);
	static void drawQuards(glm::vec3 tab[], glm::vec3 color, int n);
	static void drawCube(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color[], int index[]);
	static void drawCube(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color, int index[]);
	static void drawCubeLines(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color, int index[]);
	static void drawCubeWithLines(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color[], int index[]);
};

