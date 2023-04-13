#include "triangulo.h"

Triangulo::Triangulo(float c[6])
{
	for (int i = 0; i < 6; i++)
	{
		coordenadas[i] = c[i];
	}
}

void Triangulo::setCoordenadas(float c[6])
{
	for (int i = 0; i < 6; i++)
	{
		coordenadas[i] = c[i];
	}
}

void Triangulo::exibir()
{
		glBegin(GL_TRIANGLES);
		glVertex2f(coordenadas[0], coordenadas[1]);
		glVertex2f(coordenadas[2], coordenadas[3]);
		glVertex2f(coordenadas[4], coordenadas[5]);
		glEnd();
	
}

void Triangulo::verificarTipo() {

	lados[0] = sqrt(pow(coordenadas[2] - coordenadas[0], 2) + pow(coordenadas[3] - coordenadas[1], 2));
	lados[1] = sqrt(pow(coordenadas[4] - coordenadas[2], 2) + pow(coordenadas[5] - coordenadas[3], 2));
	lados[2] = sqrt(pow(coordenadas[4] - coordenadas[0], 2) + pow(coordenadas[5] - coordenadas[1], 2));

	if (lados[0] == lados[1] && lados[1] == lados[2])
	{
		tipo = "Equilatero";
	}
	else if (lados[0] == lados[1] || lados[0] == lados[2] || lados[1] == lados[2])
	{
		tipo = "Isosceles";
	}
	else
	{
		tipo = "Escaleno";
	}
}

string Triangulo::imprimirTipo() {
	return tipo;
}

void Triangulo::escalonar(float val)
{
	for (int i = 0; i < 6; i++)
	{
		coordenadas[i] = coordenadas[i] * val;
	}
}

void Triangulo::transladar(float valX, float valY)
{
	//não usei FOR porque tem que alternar a soma entre X e Y, não pensei numa solução pra isso
	coordenadas[0] += valX;
	coordenadas[1] += valY;
	coordenadas[2] += valX;
	coordenadas[3] += valY;
	coordenadas[4] += valX;
	coordenadas[5] += valY;
}

void Triangulo::rotacionar(float angulo)
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
}
