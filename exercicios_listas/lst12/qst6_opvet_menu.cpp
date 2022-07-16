/*
 * Faça um programa para realizar operações sobre um vetor V[5].
 * O programa deverá exibir um menu com as seguintes opções:
 * a) Gerar vetor - o programa deverá gerar V com números aleatórios,
 * sendo que o intervalo deve ser informado pelo usuário, ou seja,
 * ler dois números inteiros X e Y, sendo que o intervalo para a
 * geração dos números será de X até Y.
 * b) Mostrar vetor;
 * c) Multiplicar os valores pares armazenados no vetor por 3;
 * d) Calcular e mostrar a soma dos valores pares do vetor;
 * e) Mostrar o maior valor do vetor juntamente com sua posição.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define TAM 5

using namespace std;

void genvet(int *vet)
{
    int ini, fim;

    cout << "Informe o valor inicial do limite: ";
    cin >> ini;

    cout << "Informe o valor fim do limite: ";
    cin >> fim;

    for (int i = 0; i < TAM; i++)
        vet[i] = rand() % fim + ini;
}

void showvet(int *vet)
{
    for (int i = 0; i < TAM; i++)
        cout << "V[" << i << "] ~> " << vet[i] << endl;
}

void multivet(int *vet)
{
    for (int i = 0; i < TAM; i++)
        vet[i] *= 3;
}

void sumpnvet(int *vet)
{
    int s = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (vet[i] % 2 == 0)
            s += vet[i];
    }
    cout << "A soma dos números pares do vetor é " << s << endl;
}

void sgtnvet(int *vet)
{
    int maior = vet[0];
    int index = 0;
    for (int i = 0; i < TAM; i++)
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
            index = i;
        }
    }
    cout << "O maior valor é " << maior << ", que está na posição " << index << " do vetor." << endl;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int v[TAM], es;

    while (true)
    {
        cout << "1 - Gerar Vetor" << endl << "2 - Mostrar Vetor" << endl
            << "3 - Multiplicar (*3)" << endl << "4 - Soma dos Números Pares" << endl
            << "5 - Maior valor e seu Index" << endl << "99 - Sair" << endl << ": ";
        cin >> es;

        switch (es)
        {
            case 99:
                exit(EXIT_SUCCESS);
            case 1:
                genvet(v);
                break;
            case 2:
                showvet(v);
                break;
            case 3:
                multivet(v);
                break;
            case 4:
                sumpnvet(v);
                break;
            case 5:
                sgtnvet(v);
                break;
            default:
                cerr << "Entrada inválida!!" << endl;
                break;
        }
    }
    return 0;
}
