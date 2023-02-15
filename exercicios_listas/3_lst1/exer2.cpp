/*
 * Construa um programa que apresente um menu com as seguintes opções:
 *  a. Gerar vetor - alocar dinamicamente um vetor de 10 posições com valores aleatórios
 * no intervalor de 20 a 50;
 *  b. Mostrar vetor – mostrar os elementos do vetor;
 *  c. Sair do programa.
 *
 * Observações:
 *  - Antes de apresentar o menu, inicialize o vetor como NULL (int *vetor =
 * NULL;)
 *  - Para gerar um novo vetor, caso o vetor já tenha sido alocado, deve-se
 * liberar memória antes de alocar um novo:
 *  If (vetor != NULL)
 *  // liberar memória...
 *  - Na opção mostrar vetor, o vetor não pode ser nulo.
 */

#include <iostream>
#include <ctime>

#define VET_TAM 10

using namespace std;

const char* menu =  "1 - Gerar vetor\n"     \
                    "2 - Mostar vetor\n"    \
                    "0 - Sair\n"            \
                    ": ";

void gen_vet(int** p_vet) {
    srand(time(NULL));

    if (*p_vet) delete p_vet;
    *p_vet = new int[VET_TAM];
    for (int i = 0; i < VET_TAM; i++) {
        *(*p_vet + i) = rand() % 30 + 20;
    }
}

void show_vet(int* p_vet) {
    cout << "Vetor {\n";
    for (int i = 0; i < VET_TAM; i++) {
        cout << "\t" << *(p_vet + i) << ",\n";
    }
    cout << "}\n";
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int es;
    int* p_vet = NULL;
    while (true) {
        cout << menu;
        cin >> es;
        switch(es) {
        case 1:
            gen_vet(&p_vet);
            break;
        case 2:
            show_vet(p_vet);
            break;
        case 0:
            cout << "OK\n";
            return 0;
        }
    }
    return 0;
}
