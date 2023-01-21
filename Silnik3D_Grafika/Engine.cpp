#include "Engine.h"
#include "Cube.h"
#include <math.h>

int Engine::height = 1600;
int Engine::width = 900;
int Engine::FPS = 60;
glm::vec4 Engine::backgroundColor = { 0.0f,0.0f,0.0f,0.0f };
int Engine::counter = 0;
glm::vec3 Engine::pos = { 0 ,0, -100 };
glm::vec3 Engine::degree = { 0 ,0, 0 };
float Engine::lastX = 0;
float Engine::lastY = 0;
Cube* cube = new Cube(220.0f, 220.0f, 220.0f);
Camera Engine::camera(0, 0, glm::vec3(0.0f, 0.0f, 0.0f));

/** \brief Konstruktor Engine
 *
 * Konstruktor laczacy metody z biblioteka freeglut.
 *
 * \param[in] w przekazuje szerokosc ekranu
 * \param[in] h przekazuje wysokosc ekranu
 *
 */
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

/** \brief Metoda setBackGroundColor
 *
 * Metoda ustawia przekazany kolor tla.
 *
 * \param[in] color przekazuje wektor z kolorami do ustwaienia
 *
 */
void Engine::setBackGroundColor(glm::vec4 color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

/** \brief Metoda toggleFullScreen
 *
 * Metoda ustawia pelny ekran.
 *
 */
void Engine::toggleFullScreen() 
{
	glutFullScreenToggle();
}

/** \brief Metoda swapToPerspectiv
 *
 * Metoda sluzaca do zmiany widzenia na perspektywiczne.
 *
 */
void Engine::swapToPerspectiv()
{
	if (!camera.getPerspective())
		camera.changePerspective();
}

/** \brief Metoda swapToOrtogonal
 *
 * Metoda sluzaca do zmiany widzenia na ortogonalne.
 *
 */
void Engine::swapToOrtogonal()
{
	if (camera.getPerspective())
		camera.changePerspective();
}

/** \brief Metoda swapPrespectiveMode
 *
 * Metoda sluzaca do zmiany widzenia na perspektywiczne lub ortogonalne.
 *
 */
void Engine::swapPrespectiveMode()
{
	if (camera.getPerspective())
		swapToOrtogonal();
	else
		swapToPerspectiv();
}

/** \brief Metoda Idle
 *
 * Metoda wywolywana w tle.
 *
 */
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
<<<<<<< HEAD
=======
}

/** \brief Metoda OnClose
 *
 * Metoda wywolywana przy zamknieciu.
 *
 */
void Engine::OnClose() 
{

>>>>>>> 406db5a755c2c0c00379b16673ed7d3ea08cadbd
}

/** \brief Metoda update
 *
 * Metoda aktualizujaca.
 *
 */
void Engine::update() 
{

}

/** \brief Metoda mouse
 *
 * Metoda w zaleznosci od perspektywy zarzadza myszka.
 *
 * \param[in] x przekazuje wspolrzedna myszki
 * \param[in] y przekazuje wspolrzedna myszki
 *
 */
void Engine::mouse(int x, int y)
{
	if (camera.getPerspective())
	{
		int x1 = glutGet(GLUT_WINDOW_X);
		int y1 = glutGet(GLUT_WINDOW_Y);
<<<<<<< HEAD
		Pos.x -= (x - w / 2) / 1.0f;
		Pos.y -= (y - h / 2) / 1.0f;
		SetCursorPos(w / 2 + x1, h / 2 + y1);
		//camera.setPosition(Pos);
		//camera.setOrientation(orien);
=======
		pos.x -= (x - width / 2) / 1.0f;
		pos.y -= (y - height / 2) / 1.0f;
		SetCursorPos(width / 2 + x1, height / 2 + y1);
>>>>>>> 406db5a755c2c0c00379b16673ed7d3ea08cadbd
	}
	else
	{
		camera.setPosition({ 0,0,0 });
		camera.setOrientation({ 0,0,0 });
	}
}

/** \brief Metoda resize
 *
 * Metoda zmienia wielkosc okna.
 *
 * \param[in] w przekazuje szerokosc okna
 * \param[in] h przekazuje wysokosc okna
 *
 */
void Engine::resize(int w, int h) 
{
	Engine::width = w;
	Engine::height = h;
	camera.setWidth(w);
	camera.setHeight(h);
	glViewport(0, 0, w, h);
}

/** \brief Metoda setFPS
 *
 * Metoda ustawia liczbe fps'ow.
 *
 * \param[in] FPS przekazuje liczbe fps'ow
 *
 */
void Engine::setFPS(int FPS) 
{
	Engine::FPS = FPS;
	glutTimerFunc(1000 / FPS, OnTimer, 0);
}

/** \brief Metoda mainLoop
 *
 * Metoda sluzaca do odpalania glownej petli.
 *
 */
void Engine::mainLoop()
{
	glutMainLoop();
}

/** \brief Metoda OnKeyBoard
 *
 * Metoda w zaleznosci od wcisnietego przycisku zwieksza iteracje lub liczbe wyswietlanych figur.
 *
 * \param[in] key przekazuje przycisk
 * \param[in] x przekazuje wspolrzedna x
 * \param[in] y przekazuje wspolrzedna y
 *
 */
void Engine::OnKeyBoard(unsigned char key, int x, int y) {

	if (key == '1')
		counter--;
	if (key == '2')
		counter++;
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

/** \brief Metoda OnSpecialKey
 *
 * Metoda w zaleznosci od wcisnietego specjalnego przycisku zmienia perspektywe.
 *
 * \param[in] key przekazuje przycisk
 * \param[in] x przekazuje wspolrzedna x
 * \param[in] y przekazuje wspolrzedna y
 *
 */
void Engine::OnSpecialKey(int key, int x, int y) {
	if (key == GLUT_KEY_F1)
		toggleFullScreen();
	if (key == GLUT_KEY_F2)
		swapPrespectiveMode();
}

/** \brief Metoda OnTimer
 *
 * Metoda sluzaca do szybkosci wyswietlania obrazu.
 *
 * \param[in] val przekazuje wartosci
 *
 */
void Engine::OnTimer(int val) {
	glutTimerFunc(1000 / FPS, OnTimer, 0);

<<<<<<< HEAD
	//cube->translate({ 0.1f,0,0 });
	//cube->scale({1.0001f,1,1});

=======
	cube->translate({ 0.4f,0,0 });
	cube->scale({1.5f,1,1});
>>>>>>> 406db5a755c2c0c00379b16673ed7d3ea08cadbd
	glutPostRedisplay();
}

/** \brief Metoda Draw
 *
 * Metoda sluzaca rysujaca podane obiekty.
 *
 */
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
<<<<<<< HEAD

	//MatM = glm::rotate<float>(MatM, glm::radians(angle), glm::vec3(1, 0, 0));
	//MatM = glm::rotate<float>(MatM, glm::radians(angle / 2), glm::vec3(0, 1, 0));
	//glLoadMatrixf(glm::value_ptr(MatM));

=======
>>>>>>> 406db5a755c2c0c00379b16673ed7d3ea08cadbd
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

<<<<<<< HEAD
	switch (a)
=======
	switch (counter)
>>>>>>> 406db5a755c2c0c00379b16673ed7d3ea08cadbd
	{
	case 0:
		Drawer::drawPoints(tab, color, 10, 8);
		break;
	case 1:
		Drawer::drawPoints(tab, color1, 25, 10);
		break;
	case 2:
		Drawer::drawLines(tab, color, 10, 6);
		break;
	case 3:
		Drawer::drawLines(tab, color1, 10, 6);
		break;
	case 4:
		Drawer::drawTriangles(tab, color, 6);
		break;
	case 5:
		Drawer::drawTriangles(tab, color1, 6);
		break;
	case 6:
		Drawer::drawTrianglesStrip(tab, color, 6);
		break;
	case 7:
		Drawer::drawTrianglesStrip(tab, color1, 8);
		break;
	case 8:
		Drawer::drawTrianglesFan(tab, color, 5);
		break;
	case 9:
		Drawer::drawTrianglesFan(tab, color1, 8);
		break;
	case 10:
		cube->draw(camera.getView());
		break;
	default:
		cube->draw(camera.getView());
		break;
	};
}

/** \brief Metoda draw
 *
 * Metoda rysujaca przekazywana do freeglut.
 *
 */
void Engine::draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Draw();
	glutSwapBuffers();
	glutPostRedisplay();
	glFinish();
}