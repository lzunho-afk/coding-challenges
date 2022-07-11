/*
Escrever um algoritmo que gere uma matriz M[10][10] com valores aleatórios, intervalo de 0 a
1000. A seguir, o algoritmo deverá:
a) Mostrar a matriz gerada;
b) Determinar o elemento minimax desta matriz;
c) Mostrar a posição e o valor do elemento minimax.
- Define-se o valor denominado minimax de uma matriz como: o menor elemento da linha onde se
encontra o maior elemento da matriz.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RAND_TERM 1001
#define TAM 10

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int mtx[TAM][TAM], aux, lin, col;

    aux = mtx[0][0];
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            mtx[i][j] = rand() % RAND_TERM;
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;

            if (mtx[i][j] > aux)
            {
                aux = mtx[i][j];
                lin = i;
            }
        }
        std::cout << std::endl;
    }
    aux = mtx[lin][0];
    for (int i = 0; i < TAM; i++)
    {
        if (aux > mtx[lin][i])
        {
            aux = mtx[lin][i];
            col = i;
        }
    }
    std::cout << "O valor minimax é " << aux << ", localizado na posição (" << lin << ", " << col << ")." << std::endl;
    return 0;
}
