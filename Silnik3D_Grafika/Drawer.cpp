#include "Drawer.h"


void Drawer::drawTriangles(glm::vec3 tab[], glm::vec3 color[], int n)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_TRIANGLES, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawTriangles(glm::vec3 tab[], glm::vec3 color, int n)
{

	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawTriangles(tab, color2, n);
	delete color2;
}

void Drawer::drawTrianglesStrip(glm::vec3 tab[], glm::vec3 color[], int n)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawTrianglesStrip(glm::vec3 tab[], glm::vec3 color, int n)
{

	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawTrianglesStrip(tab, color2, n);
	delete color2;
}

void Drawer::drawTrianglesFan(glm::vec3 tab[], glm::vec3 color[], int n)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawTrianglesFan(glm::vec3 tab[], glm::vec3 color, int n)
{

	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawTrianglesFan(tab, color2, n);
	delete color2;
}


void Drawer::drawLines(glm::vec3 tab[], glm::vec3 color[], int size, int n)
{
	glLineWidth(size);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_LINES, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawLines(glm::vec3 tab[], glm::vec3 color, int size, int n)
{
	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawLines(tab, color2, size, n);
	delete color2;
}

void Drawer::drawLinesLoop(glm::vec3 tab[], glm::vec3 color[], int size, int n)
{
	glLineWidth(size);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_LINE_LOOP, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawLinesLoop(glm::vec3 tab[], glm::vec3 color, int size, int n)
{
	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawLines(tab, color2, size, n);
	delete color2;
}

void Drawer::drawPoints(glm::vec3 tab[], glm::vec3 color[], int size, int n)
{
	glPointSize(size);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_POINTS, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawPoints(glm::vec3 tab[], glm::vec3 color, int size, int n)
{
	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawPoints(tab, color2, size, n);
	delete color2;
}



void Drawer::drawQuards(glm::vec3 tab[], glm::vec3 color[], int n)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, tab);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawArrays(GL_QUADS, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Drawer::drawQuards(glm::vec3 tab[], glm::vec3 color, int n)
{

	glm::vec3* color2 = new glm::vec3[n];
	for (int i = 0; i < n; i++)
		color2[i] = color;
	drawQuards(tab, color2, n);
	delete color2;
}

void Drawer::drawCube(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color[], int index[])
{
	glm::vec3 points[3];
	glm::vec3 colors[3];
	for (int i = 0; i < 12; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			int indexCurr = index[i * 3 + j];
			points[j] = tab[indexCurr];
			colors[j] = color[indexCurr];
		}
		drawTriangles(points, colors);

	}
}
void Drawer::drawCube(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color, int index[])
{
	glm::vec3 points[3];
	glm::vec3 colors[3];
	for (int i = 0; i < 12; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			int indexCurr = index[i * 3 + j];
			points[j] = tab[indexCurr];
			colors[j] = color;
		}
		drawTriangles(points, colors);

	}
}

void Drawer::drawCubeLines(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color, int index[])
{
	glm::vec3 points[3];
	for (int i = 0; i < 12; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			int indexCurr = index[i * 3 + j];
			points[j] = tab[indexCurr];
		}
		drawLinesLoop(points, color, 2, 3);
	}
}

void Drawer::drawCubeWithLines(glm::vec3 tab[], glm::vec3 cubeNorm[], glm::vec3 color[], int index[])
{
	glm::vec3 points[3];
	glm::vec3 colors[3];
	for (int i = 0; i < 12; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			int indexCurr = index[i * 3 + j];
			points[j] = tab[indexCurr];
			colors[j] = color[0];
		}

		drawTriangles(points, colors);
		drawLinesLoop(points, (glm::vec3)(1.0f, 1.0f, 0), 2, 3);
	}
}