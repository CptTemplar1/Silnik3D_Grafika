#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include <GL/glut.h>
#include <GL/freeglut.h>
class Camera
{
	glm::mat4 view;
	glm::mat4 proj;
	glm::vec3 Position = { 0, 0, 0 };
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1000.0f, 1000.0f);
	float FOVdeg = 60, nearPlane = 1, farPlane = 1000;
	int width;
	int height;
	bool perspective = false;
	float speed = 2.5f;
	float sensitivity = 100.0f;
public:
	Camera(int width, int height, glm::vec3 position);
	void Matrix();
	void Inputs(int key);
	void setWidth(int width);
	void setHeight(int height);
	void setFOVdeg(int FOVdeg);
	void setNearPlanet(int nearPlane);
	void setFarPlane(int farPlane);
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

