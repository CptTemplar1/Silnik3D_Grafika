#include "Objects.h"
int Objects::index[] = {
	0,1,2,
	1,2,3,
	2,3,4,
	3,4,5,
	4,5,6,
	6,7,8,
	7,8,9,
	8,9,11,
	9,10,11,
	10,11,12,
	11,12,13,
	12,13,14,

	15,16,17,
	16,17,18,
	17,18,19,
	18,19,20,
	19,20,21,
	21,22,23,
	22,23,24,
	23,24,25,
	24,25,26,
	25,26,27,
	26,27,28,
	27,28,29,

};
void Objects::draw(glm::mat4 view)
{
	glm::vec3 points2[3];
	glm::vec3 color = { 0,1.0f,1.0f };
	matrix = glm::mat4(1);
	matrix = glm::translate(matrix, glm::vec3(0, 0, 500));
	glMatrixMode(GL_MODELVIEW);

	glLoadMatrixf(glm::value_ptr(view * matrix));
	for (int i = 0; i < 24; i++)
	{
		points2[0] = points[index[i * 3 + 0]];
		points2[1] = points[index[i * 3 + 1]];
		points2[2] = points[index[i * 3 + 2]];
		Drawer::drawTriangles(points2, color);
	}
}