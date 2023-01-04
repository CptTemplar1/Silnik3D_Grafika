#pragma once
#include "Drawer.h"
#include "GameObject.h"
class Cube
	: public GameObject
{
	glm::vec3 points[8];
	glm::mat4 matrix;
	glm::vec3 norms[36];
	glm::vec3 colors[8];
	static int index[];
	float r = 0;
public:
	Cube(float x, float y, float z);

	void translate(glm::vec3 p);

	void rotate(float degree, glm::vec3 p);

	void scale(glm::vec3 p);

	void draw(glm::mat4 view)
	{
		matrix = glm::mat4(1);
		r += 0.1;
		matrix = glm::rotate(glm::radians<float>(r), glm::vec3(1.0f, 0.0f, 0));

		glMatrixMode(GL_MODELVIEW);

		glLoadMatrixf(glm::value_ptr(view * matrix));
		//glutSolidCube(300);

		Drawer::drawCube(points, norms, colors, index);
		matrix = glm::translate(glm::vec3(0, 0, -500));
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view * matrix));
		Drawer::drawCube(points, norms, { 1.0f,1.0f,0 }, index);

		matrix = glm::translate(glm::vec3(0, -500, 0));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view * matrix));
		Drawer::drawCube(points, norms, { 1.0f,0.0f,0 }, index);

		matrix = glm::translate(glm::vec3(0, 500, 0));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view * matrix));
		Drawer::drawCube(points, norms, { 0.0f,0.0f,1.0f }, index);

	}



};

