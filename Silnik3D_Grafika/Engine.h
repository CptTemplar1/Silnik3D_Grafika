#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Drawer.h"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "Camera.h"

class Engine
{
	static int FPS;
	static int width, height;
	static glm::vec4 backgroundColor;
	static int counter;
	static int quantity;
	static glm::vec3 pos;
	static glm::vec3 degree;
	static float lastX, lastY;
	static Camera camera;
public:
	Engine(int width, int height);

	void setBackGroundColor(glm::vec4 color);

	static void toggleFullScreen();

	static void swapToPerspectiv();

	static void swapToOrtogonal();

	static void swapPrespectiveMode();

	static void Idle();

	static void mouse(int x, int y);

	static void resize(int w, int h);

	static void OnKeyBoard(unsigned char key, int x, int y);

	static void OnSpecialKey(int key, int x, int y);

	static void OnClose();

	static void OnTimer(int val);

	static void update();

	static void Draw();

	static void draw(void);

	static void setFPS(int FPS);

	static void mainLoop();
};


