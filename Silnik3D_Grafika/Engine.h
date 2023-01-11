#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Drawer.h"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "Camera.h"
#include "a.h"
class Engine
{
	static int FPS;
	static int w, h;
	static glm::vec4 colorBackGround;
	static int a;
	static int b;
	static glm::vec3 Pos;
	static glm::vec3 degris;
	static float lastX, lastY;
	static Camera camera;
public:
	Engine(int w, int h);
	void setBackGroundColor(glm::vec4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}
	static void toggleFullScreen();
	static void swapToPerspectiv();
	static void swapToOrtogonal();
	static void swapPrespectiveMode();


	static void Idle();

	static void mouse(int x, int y);

	static void resize(int w, int h);

	static void OnKeyBoard(unsigned char key, int x, int y);

	static void OnSpecialKey(int key, int x, int y);

	static void OnClose() {

	}

	static void OnTimer(int val);

	static void update() {

	}

	static void Draw();

	static void draw(void);

	static void setFPS(int FPS) {
		Engine::FPS = FPS;
		glutTimerFunc(1000 / FPS, OnTimer, 0);
	}
	static void mainLoop()
	{
		glutMainLoop();
	}
};


