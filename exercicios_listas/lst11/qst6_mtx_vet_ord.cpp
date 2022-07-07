/*
Escrever um algoritmo que gere uma matriz M[4][4], intervalo de 0 a 50. A seguir, o algoritmo
deverá:
a) Mostrar a matriz gerada.
b) Criar um vetor V[16] e copiar os elementos da matriz M para o vetor V.
c) Mostrar o vetor V em ordem crescente.
*/

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int m[4][4], v[16], count, aux;

    count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = rand() % 51;
            std::cout << "M[" << i << "][" << j << "] ~> " << m[i][j] << std::endl;
            v[count] = m[i][j];
            count++;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 16; i++) std::cout << "V[" << i << "] ~> " << v[i] << std::endl;
    return 0;
}
