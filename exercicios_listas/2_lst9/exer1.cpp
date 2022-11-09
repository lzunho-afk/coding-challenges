/*
Escreva um programa para manipular um vetor de 10 posições de números inteiros, o sistema deve
permitir as seguintes opções:
0 – Sair
1 – Gerar valores para o vetor entre 25 e 50
2 – Mostrar os valores do vetor, separando cada elemento com uma vírgula
3 – Mostrar o percentual de números pares no vetor
4 – Mostrar os números ímpares no vetor
5 – Mostrar a média dos elementos do vetor com uma casa decimal
OBS: este exercício deve ser resolvido usando alocação dinâmica de memória, ponteiros e aritmética de
ponteiro
*/

#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* menu =  "0 - Sair\n"                                    \
                    "1 - Gerar valores (25-50)\n"                   \
                    "2 - Mostrar valores\n"                         \
                    "3 - Mostrar o percentual de números pares\n"   \
                    "4 - Mostrar os números ímpares\n"              \
                    "5 - Mostrar a média dos elementos\n"           \
                    ": ";

void gerar_vet(int **pvet) {
    srand(time(NULL));
    for (int *i = new int(0); *i < 10; (*i)++) {
        *(*pvet + *i) = rand() % 25 + 25;
    }
}

void mostrar_vet(int **pvet) {
    cout << "{ ";
    for (int *i = new int(0); *i < 10; (*i)++) {
        cout << *(*pvet + *i) << ", ";
    }
    cout << " }\n";
}

void percentual_pares(int **pvet) {
    int *c = new int(0);
    for (int *i = new int(0); *i < 10; (*i)++) {
        if (*(*pvet + *i) % 2 == 0) {
            (*c)++;
        }
    }
    cout << "> No vetor tem " << *c * 10 << "% de números pares!\n";
}

void mostrar_impares(int **pvet) {
    cout << "> Conjunto de números ímpares: {";
    for (int *i = new int(0); *i < 10; (*i)++) {
        if (*(*pvet + *i) % 2 != 0) {
            cout << *(*pvet + *i) << ",";
        }
    }
    cout << "}\n";
}

void media_vet(int **pvet) {
    cout.precision(2);
    int *c = new int(0);
    for (int *i = new int(0); *i < 10; (*i)++) {
        (*c) += *(*pvet + *i);
    }
    cout << "> A média dos elementos do vetor é " << fixed << (*c)/10.00 << ".\n";
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int *pvet = new int[10];
    int *es = new int;

    while(true) {
        cout << menu;
        cin >> *es;

        switch(*es) {
            case 0:
                delete es;
                delete pvet;
                return 0;
            case 1:
                gerar_vet(&pvet);
                break;
            case 2:
                mostrar_vet(&pvet);
                break;
            case 3:
                percentual_pares(&pvet);
                break;
            case 4:
                mostrar_impares(&pvet);
                break;
            case 5:
                media_vet(&pvet);
                break;
            default:
                cerr << "> Escolha inválida!!\n";
                break;
        }
        cout << "---------------------------\n";
    }
    return 0;
}
