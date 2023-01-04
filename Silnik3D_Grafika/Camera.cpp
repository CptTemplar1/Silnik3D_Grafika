#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	this->width = width;
	this->height = height;
	this->Position = position;
}

void Camera::Matrix()
{

	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);

	if (perspective)
		projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);
	else
		projection = glm::ortho<float>(0, width, height, 0, -100, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(projection));

}

void Camera::Inputs(int key)
{
	// Handles key inputs
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