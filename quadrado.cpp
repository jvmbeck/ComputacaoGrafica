#include "quadrado.h"

Quadrado::Quadrado(float c[8])
{
	for (int i = 0; i < 8; i++)
	{
		coordenadas[i] = c[i];
	}
}

void Quadrado::exibir()
{
	glBegin(GL_QUADS);
	glVertex2f(coordenadas[0], coordenadas[1]);
	glVertex2f(coordenadas[2], coordenadas[3]);
	glVertex2f(coordenadas[4], coordenadas[5]);
	glVertex2f(coordenadas[6], coordenadas[7]);
	glEnd();
}

void Quadrado::mudarCor(int R, int G, int B)
{
	glColor3ub(R, G, B);
	glBegin(GL_QUADS);
	glVertex2f(coordenadas[0], coordenadas[1]);
	glVertex2f(coordenadas[2], coordenadas[3]);
	glVertex2f(coordenadas[4], coordenadas[5]);
	glVertex2f(coordenadas[6], coordenadas[7]);
	glEnd();
}

void Quadrado::escalonar(float val)
{
	for (int i = 0; i < 8; i++)
	{
		coordenadas[i] = coordenadas[i] * val;
	}
}

void Quadrado::transladar(float valX, float valY)
{
	coordenadas[0] += valX;
	coordenadas[1] += valY;
	coordenadas[2] += valX;
	coordenadas[3] += valY;
	coordenadas[4] += valX;
	coordenadas[5] += valY;
	coordenadas[6] += valX;
	coordenadas[7] += valY;
}

void Quadrado::rotacionar(float angulo)
{
	float valX1;
	float valY1;

	valX1 = coordenadas[0];
	valY1 = coordenadas[1];

	float Xauxiliar;
	float Yauxiliar;

	angulo = angulo * 3.14 / 180.0;

	coordenadas[0] -= valX1;
	coordenadas[1] -= valY1;
	Xauxiliar = cos(angulo) * coordenadas[0] - sin(angulo) * coordenadas[1];
	Yauxiliar = sin(angulo) * coordenadas[0] + cos(angulo) * coordenadas[1];
	coordenadas[0] = Xauxiliar + valX1;
	coordenadas[1] = Yauxiliar + valY1;

	coordenadas[2] -= valX1;
	coordenadas[3] -= valY1;
	Xauxiliar = cos(angulo) * coordenadas[2] - sin(angulo) * coordenadas[3];
	Yauxiliar = sin(angulo) * coordenadas[2] + cos(angulo) * coordenadas[3];
	coordenadas[2] = Xauxiliar + valX1;
	coordenadas[3] = Yauxiliar + valY1;

	coordenadas[4] -= valX1;
	coordenadas[5] -= valY1;
	Xauxiliar = cos(angulo) * coordenadas[4] - sin(angulo) * coordenadas[5];
	Yauxiliar = sin(angulo) * coordenadas[4] + cos(angulo) * coordenadas[5];
	coordenadas[4] = Xauxiliar + valX1;
	coordenadas[5] = Yauxiliar + valY1;

	coordenadas[6] -= valX1;
	coordenadas[7] -= valY1;
	Xauxiliar = cos(angulo) * coordenadas[6] - sin(angulo) * coordenadas[7];
	Yauxiliar = sin(angulo) * coordenadas[6] + cos(angulo) * coordenadas[7];
	coordenadas[6] = Xauxiliar + valX1;
	coordenadas[7] = Yauxiliar + valY1;
}
