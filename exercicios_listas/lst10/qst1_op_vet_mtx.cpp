/*
Escrever um programa que gere dois vetores X[10] e Y[10] com valores no intervalo de 0 a 50. A
seguir:
a) Ordenar o vetor X em ordem crescente. Mostre o vetor X.
b) Ordenar o vetor Y em ordem decrescente. Mostre o vetor Y.
c) Criar um vetor Z que contenha os valores ímpares de X. Mostre o vetor Z.
d) Criar um vetor W que contenha os valores pares de X. Mostre o vetor W.
e) Criar um vetor S que contenha os valores de X e Y que são maiores que 30. Mostre o vetor S.
f) Criar um vetor U que seja a união dos vetores X e Y.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define RAND_GL 51
#define TAM 10

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int x[TAM], y[TAM], z[TAM], w[TAM], s[TAM], u[TAM*2];
    int aux, count;

    for (int i = 0; i < TAM; i++)
    {
        x[i] = rand() % RAND_GL;
        y[i] = rand() % RAND_GL;
    }

    // Ordenação
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (x[i] < x[j])
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }
    std::cout << "{" << std::endl;
    for (int i = 0; i < TAM; i++)
        std::cout << "\tx[" << i << "] ~> " << y[i] << std::endl;
    std::cout << "}\n\n";

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (y[i] > y[j])
            {
                aux = y[i];
                y[i] = y[j];
                y[j] = aux;
            }
        }
    }
    std::cout << "{" << std::endl;
    for (int i = 0; i < TAM; i++)
        std::cout << "\ty[" << i << "] ~> " << y[i] << std::endl;
    std::cout << "}\n\n";

    // Ímpares & Pares
    count = 0;
    int i = 0;
    std::cout << "{" << std::endl;
    for (i; i < TAM; i++)
    {
        if (x[i] % 2 != 0)
        {
            z[count] = x[i];
            std::cout << "\tz[" << count << "] ~> " << z[count] << std::endl;
            count++;
        }
    }
    std::cout << "}\n\n";

    count = 0;
    i = 0;
    std::cout << "{" << std::endl;
    for (i; i < TAM; i++)
    {
        if (x[i] % 2 == 0)
        {
            w[count] = x[i];
            std::cout << "\tw[" << count << "] ~> " << w[count] << std::endl;
            count++;
        }
    }
    std::cout << "}\n\n";

    // Maiores que 30
    count = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (x[i] > 30)
        {
            s[count] = x[i];
            count++;
        }
        if (y[i] > 30)
        {
            s[count] = y[i];
            count++;
        }
    }
    std::cout << "{" << std::endl;
    for (int i = 0; i < count; i++)
        std::cout << "\ts[" << i << "] ~> " << s[i] << std::endl;
    std::cout << "}\n\n";

    // União de x e y (U)
    count = 0;
    for (int i = 0; i < TAM; i++)
    {
        u[count] = x[i];
        count++;
    }
    for (int i = 0; i < TAM; i++)
    {
        u[count] = y[i];
        count++;
    }
    for (int i = 0; i < TAM*2; i++)
    {
        for (int j = 0; j < TAM*2; j++)
        {
            if (u[i] == u[j] && i != j)
            {
                u[j] = -1;
            }
        }
    }
    std::cout << "{" << std::endl;
    i = 0;
    count = 0;
    for (i = 0; i < TAM*2; i++)
    {
        if (u[i] == -1) continue;
        std::cout << "\tu[" << count << "] ~> " << u[i] << std::endl;
        count++;
    }
    std::cout << "}\n\n";
    return 0;
}
