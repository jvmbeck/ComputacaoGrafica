#ifndef Quadrado_hpp
#define Quadrado_hpp

#include <GLFW/glfw3.h>
#include <math.h>

using namespace std;

class Quadrado {
	
public:

	Quadrado(float c[8]);

	void exibir();
	
	void mudarCor(int R, int G, int B); // não funciona, ainda testando

	void escalonar(float val);
	void transladar(float valX, float valY);
	void rotacionar(float val);

private:

	float coordenadas[8];
};
#endif // !Quadrado_hpp
