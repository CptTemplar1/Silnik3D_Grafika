#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/transform.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <GL/glut.h>
#include <GL/freeglut.h>
class Camera
{
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 Position = { 0,0,-300 };
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	float FOVdeg = 60, nearPlane = 1, farPlane = 1000;
	int width;
	int height;
	bool perspective = false;
	float speed = 1.1f;
	float sensitivity = 100.0f;
public:
	void setWidth(int width) { this->width = width; }
	void setHeight(int height) { this->height = height; }
	void setFOVdeg(int FOVdeg) { this->FOVdeg = FOVdeg; }
	void setNearPlanet(int nearPlane) { this->nearPlane = nearPlane; }
	void setFarPlane(int farPlane) { this->farPlane = farPlane; }
	void swapPerspective() { perspective = !perspective; }
	bool getPerspective() { return perspective; }
	void setPosition(glm::vec3 Position) { this->Position = Position; }
	void setView(glm::mat4 v) { view = v; }
	glm::vec3 getPosition() { return Position; }
	glm::mat4 getView() { return view; }
	glm::mat4 getProjection() { return projection; }
	glm::vec3 getOrientation() { return Orientation; }
	glm::vec3 getUp() { return Up; }
	void setOrientation(glm::vec3 orien) { Orientation = orien; }
	void setUp(glm::vec3 up) { Up = up; }
	Camera(int width, int height, glm::vec3 position);

	void Matrix();
	// Handles camera inputs
	void Inputs(int key);
};

