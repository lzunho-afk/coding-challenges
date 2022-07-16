/*
 * Faça um programa que gere um vetor V[15] de números inteiros e 
 * realize as seguintes operações:
 * a) Calcule a média dos valores de V.
 * b) Calcule e mostre o vetor W que será composto pelos elementos
 * do vetor V que são menores ou igual a média.
 * c) Ordene e mostre o W em ordem crescente.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TAM 15
#define RAND_TERM 100000

float media(int vet[TAM])
{
    int val = 0;
    for (int i = 0; i < TAM; i++)
        val += vet[i];
    return ((val/float(TAM)));
}

void ordwrite(int *vet, int size)
{
    int aux;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);
    srand(time(NULL));
    int v[TAM], w[TAM], wcount;
    float vmed;

    for (int i = 0; i < TAM; i++)
    {
        v[i] = rand() % RAND_TERM;
        cout << "V[" << i << "] ~> " << v[i] << endl;
    }
    vmed = media(v);
    cout << "A média do vetor 'V' é " << fixed << vmed << endl << endl;

    wcount = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (v[i] <= vmed)
        {
            w[wcount] = v[i];
            cout << "W[" << wcount << "] ~> " << w[wcount] << endl;
            wcount++;
        }
    }
    cout << endl << "Ordenação:" << endl;;
    ordwrite(w, wcount);
    for (int i = 0; i < wcount; i++)
        cout << "W[" << i << "] ~> " << w[i] << endl;
    return 0;
}
