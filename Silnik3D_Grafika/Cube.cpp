#include "Cube.h"

int Cube::index[] = {
	0,1,2, //PRZÓD
	1,2,3,
	4,5,6, //TY£
	5,6,7,
	0,1,4, //LEWO
	1,4,5,
	0,2,4, //PRAWO
	2,4,6,
	2,3,6, //GÓRA 
	3,6,7,
	1,3,5, //DÓ£
	3,5,7
};

/** \brief Konstruktor Cube
 *
 * Konstruktor przyisuje przekazane parametry do tablic.
 *
 * \param[in] x przekazuje wspolrzedna x
 * \param[in] y przekazuje wspolrzedna y
 * \param[in] z przekazuje wspolrzedna z
 *
 */
Cube::Cube(float x, float y, float z)
{
	x = x / 2;
	y = y / 2;
	z = z / 2;
	points[0] = { x,y,z };
	points[1] = { -x,y,z };
	points[2] = { x,-y,z };
	points[3] = { -x,-y,z };
	points[4] = { x,y,-z };
	points[5] = { -x,y,-z };
	points[6] = { x,-y,-z };
	points[7] = { -x,-y,-z };
	for (int i = 0; i < 8; i++)
		colors[i] = { 0,1,0 };

	for (int i = 0; i < 36; i += 3)
	{
		glm::vec3 px = glm::normalize((glm::vec3)(points[index[i]].x, points[index[i + 1]].x, points[index[i + 2]].x));
		glm::vec3 py = glm::normalize((glm::vec3)(points[index[i]].y, points[index[i + 1]].y, points[index[i + 2]].y));
		glm::vec3 pz = glm::normalize((glm::vec3)(points[index[i]].z, points[index[i + 1]].z, points[index[i + 2]].z));
		norms[i].x = px.x;
		norms[i + 1].x = px.y;
		norms[i + 2].x = px.z;
		norms[i].y = py.x;
		norms[i + 1].y = py.y;
		norms[i + 2].y = py.z;
		norms[i].z = py.x;
		norms[i + 1].z = py.y;
		norms[i + 2].z = py.z;
	}
	matrix = glm::mat4(1);

}

/** \brief Metoda transalte
 *
 * Metoda translokuje szescian.
 *
 * \param[in] p przekazuje wketor wspolrzednych
 *
 */
void Cube::translate(glm::vec3 p)
{
	glm::mat4 m
		= {
			1,0,0,p.x,
			0,0,0,p.y,
			0,0,0,p.z,
			0,0,0,1 };
	matrix *= m;
}

/** \brief Metoda rotate
 *
 * Metoda rotuje szescian.
 *
 * \param[in] degree przekazuje kat
 * \param[in] p przekazuje wketor wspolrzednych
 *
 */
void Cube::rotate(float degree, glm::vec3 p)
{
	glm::mat4 m = glm::rotate<float>(glm::radians(degree), p);
	matrix *= m;

}

/** \brief Metoda scale
 *
 * Metoda skaluje szescian.
 *
 * \param[in] p przekazuje wketor wspolrzednych
 *
 */
void Cube::scale(glm::vec3 p)
{
	glm::mat4 m = glm::scale<float>(p);
	matrix *= m;
}

/** \brief Metoda draw
 *
 * Metoda sluzaca do rysowania.
 *
 * \param[in] view przekazuje widok kamery
 *
 */
void Cube::draw(glm::mat4 view)
{
	matrix = glm::mat4(1);

	matrix = glm::translate(matrix, glm::vec3(0, 0, -800));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(view * matrix));
	Drawer::drawCube(points, norms, colors, index);
}