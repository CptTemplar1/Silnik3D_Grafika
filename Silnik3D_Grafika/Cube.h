#pragma once
#include "Drawer.h"

/** \brief Klasa Cube
 *
 * Klasa Cube jest klasa szescianu.
 *
 */
class Cube
{
	glm::mat4 matrix;/**< Matrix przechowujacy matrix szescianu */
	glm::vec3 points[8];/**< Tablica wektorow punktow szescianu */
	glm::vec3 norms[36];/**< Tablica wektorow norm szescianu */
	glm::vec3 colors[8];/**< Tablica wektorow kolorow szescianu */
	static int index[];/**< Statyczna tablica liczb calkowitych przechowujaca indexy */
public:
	Cube(float x, float y, float z);

	void translate(glm::vec3 p);

	void rotate(float degree, glm::vec3 p);

	void scale(glm::vec3 p);

	void draw(glm::mat4 view);
};

