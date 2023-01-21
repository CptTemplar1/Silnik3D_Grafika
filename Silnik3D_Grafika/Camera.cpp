#include "Camera.h"

/** \brief Konstruktor Camera
 *
 * Konstruktor przypisuje rozmiar i pozycje kamery.
 *
 * \param[in] w przekazuje szerokosc ekranu
 * \param[in] h przekazuje wysokosc ekranu
 *
 */
Camera::Camera(int width, int height, glm::vec3 position)
{
	this->width = width;
	this->height = height;
	this->Position = position;
}

/** \brief Metoda Matrix
 *
 * Metoda ustawia projekcje.
 *
 */
void Camera::Matrix()
{

	view = glm::mat4(1.0f);
	proj = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);

	if (perspective)
		proj = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);
	else
		proj = glm::ortho<float>(0, width, height, 0, -100, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(proj));

}

/** \brief Metoda Inputs
 *
 * Metoda przyjmuje przyciski do poruszania kamera.
 *
 * \param[in] key przekazuje przycisk
 *
 */
void Camera::Inputs(int key)
{
	if (key == 'w')
	{
		Position += speed * Orientation;
	}
	if (key == 'a')
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (key == 's')
	{
		Position += speed * -Orientation;
	}
	if (key == 'd')
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}

}

/** \brief Metoda setWidth
 *
 * Metoda ustawia szerokosc kamery.
 *
 * \param[in] width przekazuje szerokosc kamery
 *
 */
void Camera::setWidth(int width) 
{ 
	this->width = width; 
}

/** \brief Metoda setHeight
 *
 * Metoda ustawia wysokosc kamery.
 *
 * \param[in] height przekazuje wysokosc kamery
 *
 */
void Camera::setHeight(int height) 
{ 
	this->height = height; 
}

/** \brief Metoda setFOVdeg
 *
 * Metoda ustawia kat widzenia kamery.
 *
 * \param[in] FOVdeg przekazuje kat widzenia
 *
 */
void Camera::setFOVdeg(int FOVdeg) 
{ 
	this->FOVdeg = FOVdeg; 
}

/** \brief Metoda changePerspective
 *
 * Metoda sluzy do zmiany perspektywy.
 *
 */
void Camera::changePerspective() 
{ 
	perspective = !perspective; 
}

/** \brief Metoda getPerspective
 *
 * Metoda zwraca perspektywe.
 *
 * \return Zwraca true jesli perspektywiczne lub false jesli ortogonalne
 *
 */
bool Camera::getPerspective() 
{ 
	return perspective; 
}

/** \brief Metoda setPosition
 *
 * Metoda ustawia nowa pozycje kamery.
 *
 * \param[in] Position przekazuje pozycje kamery
 *
 */
void Camera::setPosition(glm::vec3 Position) 
{ 
	this->Position = Position; 
}

/** \brief Metoda setView
 *
 * Metoda ustawia nowy widok.
 *
 * \param[in] v przekazuje nowy widok
 *
 */
void Camera::setView(glm::mat4 v) 
{ 
	this->view = v; 
}

/** \brief Metoda getPosition
 *
 * Metoda zwraca pozycje kamery.
 *
 * \return Zwraca pozycje kamery
 *
 */
glm::vec3 Camera::getPosition() 
{ 
	return Position; 
}

/** \brief Metoda getView
 *
 * Metoda zwraca widok.
 *
 * \return Zwraca widok
 *
 */
glm::mat4 Camera::getView() 
{ 
	return view; 
}

/** \brief Metoda getProjection
 *
 * Metoda zwraca projekcje.
 *
 * \return Zwraca projekcje
 *
 */
glm::mat4 Camera::getProjection() 
{ 
	return proj; 
}

/** \brief Metoda getOrientation
 *
 * Metoda zwraca orientacje.
 *
 * \return Zwraca orientacje
 *
 */
glm::vec3 Camera::getOrientation() 
{ 
	return Orientation; 
}

/** \brief Metoda setOrientation
 *
 * Metoda ustawia orientacje.
 *
 * \param[in] orient przekazuje orientacje
 *
 */
void Camera::setOrientation(glm::vec3 orient)
{ 
	Orientation = orient; 
}