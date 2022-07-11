/*
Escrever um algoritmo que gere duas matrizes A[3][3] e B[3][3] com valores aleatórios, intervalo
de 0 a 50. A seguir, o algoritmo deverá calcular a soma das matrizes A e B e gravar o resultado em
C[3][3].
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RAND_TERM 51
#define TAM 3

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int a[TAM][TAM], b[TAM][TAM], c[TAM][TAM];

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            a[i][j] = rand() % RAND_TERM;
            b[i][j] = rand() % RAND_TERM;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "A[" << i << "][" << j << "] ~> " << a[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "---" << std::endl;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "B[" << i << "][" << j << "] ~> " << b[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "---" << std::endl;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "C[" << i << "][" << j << "] ~> " << c[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
