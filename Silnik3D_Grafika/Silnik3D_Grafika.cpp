#include <gl/glut.h>
#include <gl/freeglut.h>
#include <iostream>

/*	OpenGL - example program with FreeGLUT / GLUT
 *	(C) 2009, 2020 Grzegorz �ukawski, Politechnika �wi�tokrzyska w Kielcach
 */

 // Drawing function:
void OnDraw() {
    // Background colour (R, G, B, Alpha):
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    // Clearing the colour buffer:
    glClear(GL_COLOR_BUFFER_BIT);
    // Flushing the rendering queue:
    glFinish();	// or glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    // Preparing the window:
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Hello OpenGL");

    // Drawing callback function:
    glutDisplayFunc(OnDraw);

    glutMainLoop();
    return(0);
}