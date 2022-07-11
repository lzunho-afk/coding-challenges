/*
Escrever um algoritmo que leia uma matriz M[3][3]. A seguir, o algoritmo deverá:
a) Mostrar a matriz lida;
b) Encontrar o menor elemento da matriz e mostrá-lo juntamente com sua posição (linha, coluna).
*/

#include <iostream>

#define TAM 3

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int mtx[TAM][TAM], menor, pos[2];

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "Informe o elemento " << i << "->" << j << ": ";
            std::cin >> mtx[i][j];
        }
    }
    std::cout << std::endl;

    menor = mtx[0][0];
    pos[0] = pos[1] = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            std::cout << "MTX[" << i << "][" << j << "] ~> " << mtx[i][j] << std::endl;
            if (mtx[i][j] < menor)
            {
                menor = mtx[i][j];
                pos[0] = i;
                pos[1] = j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "O menor elemento é o número " << mtx[pos[0]][pos[1]] << ", localizado na posição (" << pos[0] << ", " << pos[1] << ")." << std::endl;
    return 0;
}
