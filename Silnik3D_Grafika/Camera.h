#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include <GL/glut.h>
#include <GL/freeglut.h>

/** \brief Klasa Camera
 *
 * Klasa Camera sluzy za widok uzytkownika.
 *
 */
class Camera
{
	glm::mat4 view;/**< Matrix przechowujacy wspolrzedne widoku */
	glm::mat4 proj;/**< Matrix przechowujacy wspolrzedne projekcji */
	glm::vec3 Position = { 0, 0, 0 };/**< Wektor przechowujacy pozycje */
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, 1.0f);/**< Wektor przechowujacy orientacje */
	glm::vec3 Up = glm::vec3(0.0f, 1000.0f, 1000.0f);/**< Wektor przechowujacy gdzie znajduje sie gora */
	float FOVdeg = 60;/**< Zmienna zmiennoprzecinkowa przechowujaca kat widzenia */
	float nearPlane = 1;/**< Zmienna zmiennoprzecinkowa przechowujaca najblizszy punkt */
	float farPlane = 1000;/**< Zmienna zmiennoprzecinkowa przechowujaca najdalszy punkt */
	int width;/**< Zmienna calkowita przchowujaca szerokosc */
	int height;/**< Zmienna calkowita przchowujaca wysokosc */
	bool perspective = false;/**< Zmienna bool przechowujaca rodzaj perspektywy */
	float speed = 2.5f;/**< Zmienna zmiennoprzecinkowa przechowujaca predkosc poruszania kamery */
	float sensitivity = 100.0f;/**< Zmienna zmiennoprzecinkowa przechowujaca czulosc */
public:
	Camera(int width, int height, glm::vec3 position);
	void Matrix();
	void Inputs(int key);
	void setWidth(int width);
	void setHeight(int height);
	void setFOVdeg(int FOVdeg);
	void changePerspective();
	bool getPerspective();
	void setPosition(glm::vec3 Position);
	void setView(glm::mat4 v);
	glm::vec3 getPosition();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::vec3 getOrientation();
	void setOrientation(glm::vec3 orient);
};

