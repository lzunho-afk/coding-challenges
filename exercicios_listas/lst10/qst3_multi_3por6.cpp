/*
Elabore um algoritmo que gere uma matriz 3x6 com valores aleatórios, intervalo de 0 a 50. Ao
final, o algoritmo deverá:
a) Mostrar os valores da matriz;
b) Pedir um valor ao usuário;
c) Multiplicar todos os valores pelo valor fornecido pelo usuário;
d) Mostrar novamente os valores da matriz.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RAND_TERM 51
#define LIN 3
#define COL 6

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int mtx[LIN][COL], val;

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mtx[i][j] = rand() % RAND_TERM;
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Por favor, informe um valor: ";
    std::cin >> val;

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mtx[i][j] *= val;
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
