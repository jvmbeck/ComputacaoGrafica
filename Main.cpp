#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

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
        cout << "Digite os pontos do triangulo (x1, y1), (x2, y2) e (x3, y3): ";
        //cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // Verifica se os pontos formam um triângulo
        float lado1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float lado2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        float lado3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        float escalonacao;


        glfwSwapBuffers(window);

        while (opcao != 4) {
            cout << "\n=== Menu ===";
            cout << "\n1. Imprimir triangulo.";
            cout << "\n2. Escalonar triangulo";
            cout << "\n3. Transalacao do triangulo";
            cout << "\n4. Encerrar";
            cout << "\nOpcao: ";
            cin >> opcao;
            
            if (opcao == 1) {
                if (lado1 < lado2 + lado3 && lado2 < lado1 + lado3 && lado3 < lado1 + lado2)
                {
                    // Exibe o triângulo
                    glBegin(GL_TRIANGLES);
                    glVertex2f(x1, y1);
                    glVertex2f(x2, y2);
                    glVertex2f(x3, y3);
                    glEnd();

                    // Verifica o tipo de triângulo
                    string tipo = verificarTipoTriangulo(lado1, lado2, lado3);
                    cout << "Tipo de triangulo: " << tipo << endl;
                    glfwSwapBuffers(window);
                }
                else
                {
                    cout << "Pontos nao formam um triangulo" << endl;
                }
            }
            else if (opcao == 2) {
                cout << "Digite por quantas vezes deseja escalonar o triangulo: ";
                cin >> escalonacao;
                x1 = x1 * escalonacao;
                x2 = x2 * escalonacao;
                x3 = x3 * escalonacao;
                y1 = y1 * escalonacao;
                y2 = y2 * escalonacao;
                y3 = y3 * escalonacao;

                lado1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                lado2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
                lado3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

                if (lado1 < lado2 + lado3 && lado2 < lado1 + lado3 && lado3 < lado1 + lado2)
                {
                    // Exibe o triângulo
                    glBegin(GL_TRIANGLES);
                    glVertex2f(x1, y1);
                    glVertex2f(x2, y2);
                    glVertex2f(x3, y3);
                    glEnd();

                    // Verifica o tipo de triângulo
                    string tipo = verificarTipoTriangulo(lado1, lado2, lado3);
                    cout << "Tipo de triangulo: " << tipo << endl;
                    glfwSwapBuffers(window);
                }
                else
                {
                    cout << "Pontos nao formam um triangulo" << endl;
                }
            }
            else if (opcao == 4) {
                return 0;
            }
            
        }

        // Atualiza a janela
        glfwSwapBuffers(window);
    }

    // Encerra o GLFW
    glfwTerminate();

    return 0;
}