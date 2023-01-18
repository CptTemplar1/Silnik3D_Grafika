#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Drawer.h"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "Camera.h"

/** \brief Klasa Engine
 *
 * Klasa Engine jest to glowna klasa silnika.
 *
 */
class Engine
{
	static int FPS;/**< Zmienna statyczna calkowita przechowujaca liczbe fps'ow */
	static int width;/**< Zmienna statyczna calkowita przechowujaca szerokosc ekranu */
	static int height;/**< Zmienna statyczna calkowita przechowujaca wysokosc ekranu */
	static glm::vec4 backgroundColor;/**< Statyczny wektor przechowujacy kolor tla */
	static int counter;/**< Zmienna statyczna calkowita przechowujaca liczbe iteracji */
	static int quantity;/**< Zmienna statyczna calkowita przechowujaca ilosc figur */
	static glm::vec3 pos;/**< Statyczny wektor przechowujacy pozycje */
	static glm::vec3 degree;/**< Statyczny wektor przechowujacy kat widzenia */
	static float lastX;/**< Zmienna statyczna zmiennoprzecinkowa przechowujaca ostatnia pozycje x */
	static float lastY;/**< Zmienna statyczna zmiennoprzecinkowa przechowujaca ostatnia pozycje x */
	static Camera camera;/**< Statyczny obiekt kamery */
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


