#include "Engine.h"
#include "Cube.h"
#include <math.h>

int Engine::h = 600;
int Engine::w = 300;
int Engine::FPS = 60;
glm::vec4 Engine::colorBackGround = { 0.0f,0.0f,0.0f,0.0f };
int Engine::a = 12;
int Engine::b = 3;
glm::vec3 Engine::Pos = { 0 ,0,-100 };
glm::vec3 Engine::degris = { 0 ,0,0 };
float Engine::lastX = 0;
float Engine::lastY = 0;
Cube* cube = new Cube(150.0f, 150.0f, 150.0f);
a litera = a(100);
Camera* Engine::camera = new Camera(w, h, glm::vec3(0.0f, 0.0f, 0.0f));
Player* Engine::player = new Player(camera);

Engine::Engine(int w, int h)
{
	this->w = w;
	this->h = h;


	glutInitWindowSize(w, h);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glDisable(CURSOR_SHOWING);

	glutCreateWindow("SILNIK #3D");
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
}



void Engine::toggleFullScrean() {

	glutFullScreenToggle();
}
void Engine::swapToPerspectiv()
{
	if (!camera->getPerspective())
		camera->swapPerspective();
}
void Engine::swapToOrtogonal()
{
	if (camera->getPerspective())
		camera->swapPerspective();
}

void Engine::swapPrespectiveMode()
{
	if (camera->getPerspective())
		swapToOrtogonal();
	else
		swapToPerspectiv();
}


void Engine::Idle() {

	static int last_time;
	int now_time = glutGet(GLUT_ELAPSED_TIME);

	if (last_time > 0) {
		float times = (now_time - last_time) / 1000.0f;

	}
	last_time = now_time;
	glutPostRedisplay();


}

void Engine::mouse(int x, int y)
{
	if (camera->getPerspective())
	{

		int x1 = glutGet(GLUT_WINDOW_X);
		int y1 = glutGet(GLUT_WINDOW_Y);
		//camera->setPosition(Pos);

		//camera->setOrientation(orien);
		player->MouseMove((x - w / 2), (y - h / 2));
		SetCursorPos(w / 2 + x1, h / 2 + y1);
	}
	else
	{
		camera->setPosition({ 0,0,0 });
		camera->setOrientation({ 0,0,0 });
	}

}

void Engine::resize(int w, int h) {
	Engine::w = w;
	Engine::h = h;
	camera->setWidth(w);
	camera->setHeight(h);
	glViewport(0, 0, w, h);
}

void Engine::OnKeyBoard(unsigned char key, int x, int y) {

	if (key == 'p')
		a--;
	if (key == 'o')
		a++;
	if (key == 'q')
		b--;
	if (key == 'e')
		b++;

	if (key == 'w')
		Pos.z += 3;
	if (key == 's')
		Pos.z -= 3;
	if (key == 'r')
	{
		Pos.x = 0;
		Pos.y = 0;
		Pos.z = -300;
		camera->setPosition(Pos);
	}
	if (key == 0x1B)
		exit(0);
	player->KeyPress(key);
}

void Engine::OnSpecialKey(int key, int x, int y) {
	if (key == GLUT_KEY_F1)
		toggleFullScrean();
	if (key == GLUT_KEY_F2)
		swapPrespectiveMode();
}
void Engine::OnTimer(int val) {
	glutTimerFunc(1000 / FPS, OnTimer, 0);


	//cube->translate({ 0.1f,0,0 });
	//cube->scale({1.0001f,1,1});

	glutPostRedisplay();

}

void Engine::Draw()
{

	if (camera->getPerspective())
	{
		player->update();
	}
	else
	{
		camera->Matrix();
		camera->setPosition({ 0,0,0 });
		camera->setOrientation({ 0,0,1 });
	}





	//MatM = glm::rotate<float>(MatM, glm::radians(angle), glm::vec3(1, 0, 0));
	//MatM = glm::rotate<float>(MatM, glm::radians(angle / 2), glm::vec3(0, 1, 0));
	//glLoadMatrixf(glm::value_ptr(MatM));

	glm::vec3 tab[] = {
		{300,100,000},
		{300,300,0},
		{100,500,0},
		{500,600,0},
		{700,300,0},
		{200,600,0},
	};
	glm::vec3 color[] = {
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
		{1.0f,1.0f,0.0f },
		{0.0f,1.0f,1.0f},
		{1.0f,0.0f,1.0f},
		{1.0f,0.0f,0.0f},
		{1.0f,1.0f,0.0f},
		{1.0f,0.0f,1.0f}
	};

	glm::vec3 c = { 1.0f,0.0f,1.0f };






	switch (a)
	{
	case 0:
		Drawer::drawTriangles(tab, color, 6);
		break;
	case 1:
		Drawer::drawTriangles(tab, c, 6);
		break;
	case 2:
		Drawer::drawLines(tab, color, 10, 6);
		break;
	case 3:
		Drawer::drawLines(tab, c, 10, 6);
		break;
	case 4:
		Drawer::drawTrianglesStrip(tab, color, b);
		break;
	case 5:
		Drawer::drawTrianglesStrip(tab, c, b);
		break;
	case 6:
		Drawer::drawTrianglesFan(tab, color, b);
		break;
	case 7:
		Drawer::drawTrianglesFan(tab, c, b);
		break;
	case 8:
		Drawer::drawPoints(tab, color, 10, 6);
		break;
	case 9:
		Drawer::drawPoints(tab, c, 10, 6);
		break;
	case 10:
		Drawer::drawQuards(tab, color, b);
		break;
	case 11:
		Drawer::drawQuards(tab, c, b);
		break;

	case 13:

		cube->draw(camera->getView());

		break;
	case 12:

		litera.draw(camera->getView());

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