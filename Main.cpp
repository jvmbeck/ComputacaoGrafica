#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include <cmath>

using namespace std;

// Função para verificar o tipo de triângulo
string verificarTipoTriangulo(float lado1, float lado2, float lado3)
{
    if (lado1 == lado2 && lado2 == lado3)
    {
        return "Equilatero";
    }
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
    {
        return "Isosceles";
    }
    else
    {
        return "Escaleno";
    }
}

void exibeTriangulo(float x1, float y1, float x2, float y2, float x3, float y3) {

    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

int AcharPonto(float x1, float y1, float x2, float y2, float x3, float y3) {

    int ponto = 0;
    if (x1 < x2 && x1 < x3) {
        ponto = 1;
    }
    else {
        ponto = 0;
    };
    return ponto;
    
}

int main()
{
    // Inicializa o GLFW
    glfwInit();

    // Cria a janela
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Triangulo", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Loop principal
    while (!glfwWindowShouldClose(window))
    {
        // Verifica eventos
        glfwPollEvents();

        // Limpa a tela
        glClear(GL_COLOR_BUFFER_BIT);

        int opcao = 0;
        // Lê os pontos
        //float x1, y1, x2, y2, x3, y3;
        float x1 = -0.5, y1 = -0.5, x2 = 0, y2 = 0.5, x3 = 0.5, y3 = -0.5;
        //float x1 = -0.5, y1 = -0.25, x2 = 0.5, y2 = 1, x3 = 1, y3 = -0.25;
        //cout << "Digite os pontos do triangulo (x1, y1), (x2, y2) e (x3, y3): ";
        //cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // Verifica se os pontos formam um triângulo
        float lado1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float lado2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        float lado3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        float escalonacao;


        glfwSwapBuffers(window);

        if (AcharPonto(x1, y1, x2, y2, x3, y3) == 1) {
            cout << "Ponto verificado";
            cout << "\nTrabalhando com Ponto Esquerdo";
        }
        else {
            cout << "Erro na localização do ponto!!!";
        };

        float VetorDistancia[4];
        VetorDistancia[0] = x2 - x1;
        VetorDistancia[1] = x3 - x1;
        VetorDistancia[2] = y2 - y1;
        VetorDistancia[3] = y3 - y1;


        while (opcao != 5) {
            cout << "\n=== Menu ===";
            cout << "\n1. Imprimir triangulo.";
            cout << "\n2. Escalonar triangulo";
            cout << "\n3. Transalacao do triangulo";
            cout << "\n4. Rotacao do triangulo";
            cout << "\n5. Encerrar";
            cout << "\nOpcao: ";
            cin >> opcao;

            switch (opcao) {
            case 1:
                if (lado1 < lado2 + lado3 && lado2 < lado1 + lado3 && lado3 < lado1 + lado2)
                {
                    exibeTriangulo(x1, y1, x2, y2, x3, y3);

                    cout << "Tipo de triangulo: " << verificarTipoTriangulo(lado1, lado2, lado3) << endl;
                    glfwSwapBuffers(window);
                }
                else
                {
                    cout << "Pontos nao formam um triangulo" << endl;
                }
                break;

            case 2:
                cout << "Digite por quantas vezes deseja escalonar o triangulo: ";
                cin >> escalonacao;

                x1 = x1 * escalonacao;
                x2 = x2 * escalonacao;
                x3 = x3 * escalonacao;
                y1 = y1 * escalonacao;
                y2 = y2 * escalonacao;
                y3 = y3 * escalonacao;

                exibeTriangulo(x1, y1, x2, y2, x3, y3);

                cout << "Tipo de triangulo: " << verificarTipoTriangulo(lado1, lado2, lado3) << endl;
                glfwSwapBuffers(window);
                break;

            case 3:
                float XTemp;
                float YTemp;

                cout << "Digite nova posicao em X: ";
                cin >> XTemp;
                cout << "Digite nova posicao em Y: ";
                cin >> YTemp;

                x1 = x1 + XTemp;
                y1 = y1 + YTemp;
                x2 = x2 + XTemp;
                y2 = y2 + YTemp;
                x3 = x3 + XTemp;
                y3 = y3 + YTemp;


                glClear(GL_COLOR_BUFFER_BIT);

                exibeTriangulo(x1, y1, x2, y2, x3, y3);

                cout << "Tipo de triangulo: " << verificarTipoTriangulo(lado1, lado2, lado3) << endl;
                glfwSwapBuffers(window);
                break;

            case 4:
                int graus;

                cout << "Digite quantos graus quer rotacionar: ";
                cin >> graus;

                float valX1;
                float valY1;

                valX1 = x1;
                valY1 = y1;

                cout << "\n\n=== Antes ===";
                cout << "\n X1: " << x1 << " Y1: " << y1;
                cout << "\n X2: " << x2 << " Y2: " << y2;
                cout << "\n X3: " << x3 << " Y3: " << y3;


                //Translação do primeiro vértice para a coordenada (0,0) e arrastando todos os outros lados de acordo
                /*
                x1 -= valX1;
                y1 -= valY1;
                x2 -= valX1;
                y2 -= valY1;
                x3 -= valX1;
                y3 -= valY1;
                */

                cout << "\n\n=== Transalacao para o ponto (0,0) ===";
                cout << "\n X1: " << x1 << " Y1: " << y1;
                cout << "\n X2: " << x2 << " Y2: " << y2;
                cout << "\n X3: " << x3 << " Y3: " << y3;
                float Xauxiliar;
                float Yauxiliar;

                float rad;
                rad = graus * 3.14 / 180.0;

                x1 = x1 - valX1;
                y1 = y1 - valY1;

                cout << "\n\n=== Transalacao para o ponto (0,0) ===";
                cout << "\n X1: " << x1 << " Y1: " << y1;

                Xauxiliar = cos(rad) * x1 - sin(rad) * y1;
                Yauxiliar = sin(rad) * x1 + cos(rad) * y1;

                cout << "\n\n=== Rotacao ===";
                cout << "\n XAuxiliar: " << Xauxiliar << " YAuxiliar: " << Yauxiliar;

                x1 = Xauxiliar + valX1;
                y1 = Yauxiliar + valY1;

                cout << "\n\n=== Transalacao volta ponto original ===";
                cout << "\n X1: " << x1 << " Y1: " << y1;

                x2 = x2 - valX1;
                y2 = y2 - valY1;

                cout << "\n\n=== Transalacao para o ponto (0,0) ===";
                cout << "\n X2: " << x2 << " Y2: " << y2;

                Xauxiliar = cos(rad) * x2 - sin(rad) * y2;
                Yauxiliar = sin(rad) * x2 + cos(rad) * y2;


                cout << "\n\n=== Rotacao ===";
                cout << "\n XAuxiliar: " << Xauxiliar << " YAuxiliar: " << Yauxiliar;

                x2 = Xauxiliar + valX1;
                y2 = Yauxiliar + valY1;

                cout << "\n\n=== Transalacao volta ponto original ===";
                cout << "\n X2: " << x2 << " Y2: " << y2;

                x3 = x3 - valX1;
                y3 = y3 - valY1;

                cout << "\n\n=== Transalacao para o ponto (0,0) ===";
                cout << "\n X3: " << x3 << " Y3: " << y3;

                Xauxiliar = cos(rad) * x3 - sin(rad) * y3;
                Yauxiliar = sin(rad) * x3 + cos(rad) * y3;

                cout << "\n\n=== Rotacao ===";
                cout << "\n XAuxiliar: " << Xauxiliar << " YAuxiliar: " << Yauxiliar;

                x3 = Xauxiliar + valX1;
                y3 = Yauxiliar + valY1;

                cout << "\n\n=== Transalacao volta ponto original ===";
                cout << "\n X3: " << x3 << " Y3: " << y3;

                /*
                x1 += valX1;
                y1 += valY1;
                x2 += valX1;
                y2 += valY1;
                x3 += valX1;
                y3 += valY1;
                */

                glClear(GL_COLOR_BUFFER_BIT);

                exibeTriangulo(x1, y1, x2, y2, x3, y3);

                cout << "Tipo de triangulo: " << verificarTipoTriangulo(lado1, lado2, lado3) << endl;
                glfwSwapBuffers(window);


                break;

            case 5:
                return 0;
                break;
            }

        }

        // Atualiza a janela
        glfwSwapBuffers(window);
    }

    // Encerra o GLFW
    glfwTerminate();

    return 0;
}
