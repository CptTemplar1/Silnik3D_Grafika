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
	proj = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);

	if (perspective)
		proj = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);
	else
		proj = glm::ortho<float>(0, width, height, 0, -100, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(proj));

}

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

void Camera::setWidth(int width) 
{ 
	this->width = width; 
}

void Camera::setHeight(int height) 
{ 
	this->height = height; 
}

void Camera::setFOVdeg(int FOVdeg) 
{ 
	this->FOVdeg = FOVdeg; 
}

void Camera::setNearPlanet(int nearPlane) 
{ 
	this->nearPlane = nearPlane; 
}

void Camera::setFarPlane(int farPlane) 
{ 
	this->farPlane = farPlane; 
}

void Camera::changePerspective() 
{ 
	perspective = !perspective; 
}

bool Camera::getPerspective() 
{ 
	return perspective; 
}

void Camera::setPosition(glm::vec3 Position) 
{ 
	this->Position = Position; 
}

void Camera::setView(glm::mat4 v) 
{ 
	view = v; 
}

glm::vec3 Camera::getPosition() 
{ 
	return Position; 
}

glm::mat4 Camera::getView() 
{ 
	return view; 
}

glm::mat4 Camera::getProjection() 
{ 
	return proj; 
}

glm::vec3 Camera::getOrientation() 
{ 
	return Orientation; 
}

void Camera::setOrientation(glm::vec3 orient)
{ 
	Orientation = orient; 
}