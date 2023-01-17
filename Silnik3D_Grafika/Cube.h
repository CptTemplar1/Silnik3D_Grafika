#pragma once
#include "Drawer.h"

class Cube
{
	glm::mat4 matrix;
	glm::vec3 points[8];
	glm::vec3 norms[36];
	glm::vec3 colors[8];
	static int index[];
	float r = 0;
public:
	Cube(float x, float y, float z);

	void translate(glm::vec3 p);

	void rotate(float degree, glm::vec3 p);

	void scale(glm::vec3 p);

	void draw(glm::mat4 view);
};

