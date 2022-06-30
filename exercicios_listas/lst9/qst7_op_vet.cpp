/*
 * Crie um algoritmo que gere dinamicamente valores para preencher um vetor de 10 elementos do
 * tipo float, em seguida apresente os elementos do vetor e realize as seguintes operações:
 * - Mostra a média dos elementos do vetor;
 * - Mostrar o maior e o menor elemento do vetor;
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    float vet[10], sum, media, maior, menor;
    float max = 100000.00;
    float min = 1.00;

    sum = 0;
    for (int i = 0; i < 10; i++)
    {
        vet[i] = min + rand() * (max - min) / RAND_MAX;
        std::cout << "Vet[" << i << "] ~> " << vet[i] << std::endl;
        sum += vet[i];
    }

    media = sum/10.00;
    maior = vet[0];
    menor = vet[0];

    for (int i = 0; i < 10; i++)
    {
        if (vet[i] >= maior) maior = vet[i];
        if (vet[i] <= menor) menor = vet[i];
    }
    std::cout << "\nMédia - " << media << std::endl
            << "Maior - " << maior << std::endl
            << "Menor - " << menor << std::endl;
    return 0;
}
