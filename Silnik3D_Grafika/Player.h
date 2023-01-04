#pragma once
#include "../Camera.h"
#include "../../glm/gtx/matrix_cross_product.hpp"
#include "GameObject.h"
class Player
	:public GameObject
{
	Camera* camera;
	glm::vec3 rotate;

	glm::vec3 pos;
	glm::vec3 movementSpeed = { 0,0,3.0f };
public:

	Player(Camera* camera)
	{
		this->camera = camera;
	}
	void update()
	{

		camera->Matrix();
	}

	void KeyPress(unsigned char key)
	{
		if (key == 'w')
		{
			movePos(camera->getOrientation());
		}
		if (key == 's')
		{
			movePos(-camera->getOrientation());
		}
		if (key == 'a')
		{
			movePos(-glm::cross(camera->getOrientation(), camera->getUp()));

		}
		if (key == 'd')
		{
			movePos(glm::cross(camera->getOrientation(), camera->getUp()));
		}
	}
	void movePos(glm::vec3 move)
	{
		pos += move;

		camera->setPosition(pos);
	}
	void MousePress(unsigned char key)
	{

	}
	void MouseMove(float x, float y)
	{
		rotate.x += x;
		rotate.y -= y;
		int size = 20;
		if (rotate.y > 89.0f * size)
			rotate.y = 89.0f * size;
		if (rotate.y < -89.0f * size)
			rotate.y = -89.0f * size;
		glm::vec3 front;
		front.x = cos(glm::radians<float>(rotate.x / size)) * cos(glm::radians<float>(rotate.y / size));
		front.y = sin(glm::radians<float>(rotate.y / size));
		front.z = sin(glm::radians<float>(rotate.x / size)) * cos(glm::radians<float>(rotate.y / size));
		front = normalize(front);
		camera->setOrientation(front);
	}
};

