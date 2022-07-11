/*
Crie um algoritmo que leia um número inteiro N. Em seguida, gere uma matriz quadrada N x N com
valores aleatórios, intervalo de 0 a 9. Ao final, o calcule e mostre a soma:
a) Dos elementos da linha 4;
b) Dos elementos da coluna 2;
c) Dos elementos da diagonal principal;
d) Dos elementos da diagonal secundária
e) De todos os elementos da matriz.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RAND_TERM 10

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int n, sa_mtx, smtx1, smtx2, aux;

    std::cout << "Por favor, informe o valor de N: ";
    std::cin >> n;

    int mtx[n][n];
    sa_mtx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mtx[i][j] = rand() % RAND_TERM;
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;
            sa_mtx += mtx[i][j];
        }
        std::cout << std::endl;
    }

    smtx1 = smtx2 = 0;
    for (int i = 0; i < n; i++)
    {
        smtx1 += mtx[3][i];
        smtx2 += mtx[1][i];
    }
    std::cout << "A soma dos elementos da linha 4 é " << smtx1 << std::endl
            << "A soma dos elementos da linha 2 é " << smtx2 << std::endl;

    smtx1 = smtx2 = 0;
    aux = n-1;
    for (int i = 0; i < n; i++)
    {
        smtx1 += mtx[i][i];
        smtx2 += mtx[i][aux];
        aux--;
    }
    std::cout << "A soma dos elementos da diagonal principal é " << smtx1 << std::endl
            << "A soma dos elementos da diagonal secundária é " << smtx2 << std::endl;
    return 0;
}
