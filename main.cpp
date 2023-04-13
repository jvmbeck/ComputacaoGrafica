#include "triangulo.h"
#include "quadrado.h"

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
        float escalonacao;

        //Tamanhos base pro triangulo e quadrado
        float coordenadasTriangulo[6] = { -0.5, -0.5, 0, 0.5, 0.5, -0.5 };
        float coordenadasQuadrado[8] =  { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };

        Triangulo T1(coordenadasTriangulo);
        Quadrado Q1(coordenadasQuadrado);

        glfwSwapBuffers(window);

        while (opcao != 5) {
            glClear(GL_COLOR_BUFFER_BIT);
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
                Q1.exibir();
                //Q1.mudarCor(1,0,0);

                //T1.verificarTipo();
                //T1.imprimirTipo();
                glfwSwapBuffers(window);
                break;

            case 2:
                cout << "Digite por quantas vezes deseja escalonar o triangulo: ";
                cin >> escalonacao;

                Q1.escalonar(escalonacao);
                Q1.exibir();

                //T1.verificarTipo();
                //T1.imprimirTipo();
                glfwSwapBuffers(window);
                break;

            case 3:
                float XTemp;
                float YTemp;

                cout << "Digite nova posicao em X: ";
                cin >> XTemp;
                cout << "Digite nova posicao em Y: ";
                cin >> YTemp;

                Q1.transladar(XTemp, YTemp);
                Q1.exibir();

                //T1.verificarTipo();
                //T1.imprimirTipo();
                glfwSwapBuffers(window);

                glfwSwapBuffers(window);
                break;

            case 4:
                float graus;

                cout << "Digite quantos graus quer rotacionar: ";
                cin >> graus;

                Q1.rotacionar(graus);
                Q1.exibir();

                //T1.verificarTipo();
                //T1.imprimirTipo();
                glfwSwapBuffers(window);

                break;

            case 5:
                return 0;
                break;

            default:
                
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
