#include "Engine.h"
#include "Cube.h"
#include <math.h>

int Engine::height = 1600;
int Engine::width = 900;
int Engine::FPS = 60;
glm::vec4 Engine::backgroundColor = { 0.0f,0.0f,0.0f,0.0f };
int Engine::counter = 0;
int Engine::quantity = 3;
glm::vec3 Engine::pos = { 0 ,0, -100 };
glm::vec3 Engine::degree = { 0 ,0, 0 };
float Engine::lastX = 0;
float Engine::lastY = 0;
Cube* cube = new Cube(120.0f, 120.0f, 120.0f);
Camera Engine::camera(0, 0, glm::vec3(0.0f, 0.0f, 0.0f));

Engine::Engine(int w, int h)
{
	this->width = w;
	this->height = h;

	glutInitWindowSize(w, h);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glDisable(CURSOR_SHOWING);

	glutCreateWindow("Silnik3D_Grafika");
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glutReshapeFunc(resize);
	glutDisplayFunc(draw);
	glutIdleFunc(Idle);
	glutSpecialFunc(OnSpecialKey);
	glutKeyboardFunc(OnKeyBoard);
	glutCloseFunc(OnClose);
	glutPassiveMotionFunc(mouse);

	glutTimerFunc(1000 / FPS, OnTimer, 0);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	swapPrespectiveMode();
	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	camera = Camera(w, h, glm::vec3(0.0f, 0.0f, 0.0f));
}

void Engine::setBackGroundColor(glm::vec4 color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void Engine::toggleFullScreen() 
{
	glutFullScreenToggle();
}

void Engine::swapToPerspectiv()
{
	if (!camera.getPerspective())
		camera.changePerspective();
}

void Engine::swapToOrtogonal()
{
	if (camera.getPerspective())
		camera.changePerspective();
}

void Engine::swapPrespectiveMode()
{
	if (camera.getPerspective())
		swapToOrtogonal();
	else
		swapToPerspectiv();
}


void Engine::Idle() 
{

	static int last_time;
	int now_time = glutGet(GLUT_ELAPSED_TIME);

	if (last_time > 0) 
	{
		float times = (now_time - last_time) / 1000.0f;
	}
	last_time = now_time;
	glutPostRedisplay();
}

void Engine::OnClose() 
{

}

void Engine::update() 
{

}

void Engine::mouse(int x, int y)
{
	if (camera.getPerspective())
	{
		int x1 = glutGet(GLUT_WINDOW_X);
		int y1 = glutGet(GLUT_WINDOW_Y);
		pos.x -= (x - width / 2) / 1.0f;
		pos.y -= (y - height / 2) / 1.0f;
		SetCursorPos(width / 2 + x1, height / 2 + y1);
	}
	else
	{
		camera.setPosition({ 0,0,0 });
		camera.setOrientation({ 0,0,0 });
	}
}

void Engine::resize(int w, int h) 
{
	Engine::width = w;
	Engine::height = h;
	camera.setWidth(w);
	camera.setHeight(h);
	glViewport(0, 0, w, h);
}

void Engine::setFPS(int FPS) 
{
	Engine::FPS = FPS;
	glutTimerFunc(1000 / FPS, OnTimer, 0);
}

void Engine::mainLoop()
{
	glutMainLoop();
}

void Engine::OnKeyBoard(unsigned char key, int x, int y) {

	if (key == '1')
		counter--;
	if (key == '2')
		counter++;
	if (key == '3')
		quantity--;
	if (key == '4')
		quantity++;
	if (key == 'w')
		pos.z += 3;
	if (key == 's')
		pos.z -= 3;
	if (key == 'r')
	{
		pos.x = 0;
		pos.y = 0;
		pos.z = 0;
		camera.setPosition(pos);
	}
	if (key == 0x1B)
		exit(0);
	camera.Inputs(key);
}

void Engine::OnSpecialKey(int key, int x, int y) {
	if (key == GLUT_KEY_F1)
		toggleFullScreen();
	if (key == GLUT_KEY_F2)
		swapPrespectiveMode();
}

void Engine::OnTimer(int val) {
	glutTimerFunc(1000 / FPS, OnTimer, 0);

	cube->translate({ 0.4f,0,0 });
	cube->scale({1.5f,1,1});
	glutPostRedisplay();
}

void Engine::Draw()
{
	camera.Matrix();
	if (camera.getPerspective())
	{
		glm::mat4 view = camera.getView();
		glm::mat4 ry = glm::rotate<float>(glm::degrees<float>(pos.y / 36000), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rx = glm::rotate<float>(glm::degrees<float>(pos.x / 36000), glm::vec3(0.0f, -1.0f, 0.0f));
		ry = rx * ry;
		camera.setView(view * ry);
	}
	else
	{
		camera.setPosition({ 0,0,0 });
		camera.setOrientation({ 0,0,-8 });
	}
	glm::vec3 tab[] = {
		{300,200,0},
		{400,400,0},
		{200,600,0},
		{500,600,0},
		{800,500,0},
		{200,500,0},
	};
	glm::vec3 color[] = {
		{1.0f,1.0f,1.0f },
		{0.0f,1.0f,1.0f},
		{1.0f,0.0f,1.0f},
		{1.0f,0.0f,0.0f},
		{1.0f,1.0f,1.0f},
		{1.0f,1.0f,0.0f },
		{0.0f,1.0f,1.0f},
		{1.0f,0.0f,1.0f},
		{1.0f,0.0f,0.0f},
		{1.0f,1.0f,0.0f},
		{1.0f,1.0f,0.0f },
		{0.0f,1.0f,1.0f},
		{1.0f,0.0f,1.0f},
		{1.0f,0.0f,0.0f},
		{1.0f,1.0f,0.0f},
		{1.0f,1.0f,1.0f}
	};

	glm::vec3 color1 = { 0.0f,1.0f,0.0f };

	switch (counter)
	{
	case 0:
		Drawer::drawTriangles(tab, color, 6);
		break;
	case 1:
		Drawer::drawTriangles(tab, color1, 6);
		break;
	case 2:
		Drawer::drawLines(tab, color, 10, 6);
		break;
	case 3:
		Drawer::drawLines(tab, color1, 10, 6);
		break;
	case 4:
		Drawer::drawTrianglesStrip(tab, color, quantity);
		break;
	case 5:
		Drawer::drawTrianglesStrip(tab, color1, quantity);
		break;
	case 6:
		Drawer::drawTrianglesFan(tab, color, quantity);
		break;
	case 7:
		Drawer::drawTrianglesFan(tab, color1, quantity);
		break;
	case 8:
		Drawer::drawPoints(tab, color, 10, 6);
		break;
	case 9:
		Drawer::drawPoints(tab, color1, 10, 6);
		break;
	case 10:
		Drawer::drawQuards(tab, color, quantity);
		break;
	case 11:
		Drawer::drawQuards(tab, color1, quantity);
		break;
	case 12:
		cube->draw(camera.getView());
		break;
	default:
		Drawer::drawTriangles(tab, color, 6);
		break;
	};
}

void Engine::draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Draw();
	glutSwapBuffers();
	glutPostRedisplay();
	glFinish();
}