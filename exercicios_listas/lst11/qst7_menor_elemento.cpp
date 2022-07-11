/*
Escrever um algoritmo que leia uma matriz M[3][3]. A seguir, o algoritmo dever�:
a) Mostrar a matriz lida;
b) Encontrar o menor elemento da matriz e mostr�-lo juntamente com sua posi��o (linha, coluna).
*/

#include <iostream>

#define TAM 3

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int mtx[TAM][TAM], menor, lin, col;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "Informe o valor do elemento " << i << "->" << j << ": ";
            std::cin >> mtx[i][j];
        }
    }

    menor = mtx[0][0];
    lin = col = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (menor > mtx[i][j])
            {
                menor = mtx[i][j];
                lin = i;
                col = j;
            }
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "O menor elemento da matriz � " << menor << ", localizado na posi��o (" << lin << ", " << col << ")." << std::endl;
    return 0;
}
