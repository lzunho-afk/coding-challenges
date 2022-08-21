/*
 * Crie um programa que manipule um vetor V[10] que deve ser preenchido
 * com valores inteiros entre 15 e 50, sem números repetidos.
 * Após gerar o vetor o programa deverá:
 *   - Exibir o vetor na tela
 *   - Exibir o vetor em ordem decrescente
 *   - Exibir o percentual de valores pares e ímpares constantes no vetor
 *   - Exibir a soma e a média dos elementos do vetor.
 */

#include <iostream>

#define TAM 10

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int vet[TAM], aux, aux2;

    // Gera e mostra o vetor
    cout << "Vet => {" << endl;
    for (int i = 0; i < TAM; i++) {
        vet[i] = (rand() % 35) + 15;
        for (int j = 0; j < i; j++) {
            if (vet[j] == vet[i]) {
                vet[i] = (rand() % 35) + 15;
                j = 0;
            }
        }
        cout << "\t" << i << ": " << vet[i] << endl;
    }
    cout << "}" << endl;

    // Traduz o vetor para ordem decrescente
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    // Mostra o vetor
    cout << "Vet (ord.) => {" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\t" << i << ": " << vet[i] << endl;
    }
    cout << "}" << endl;

    // Percentual de pares e ímpares
    aux = aux2 = 0;
    for (int i = 0; i < TAM; i++) {
        if (vet[i] % 2 == 0) {
            aux++;
        } else {
            aux2++;
        }
    }
    cout << "\% de valores pares: " << (100.00*aux)/TAM << endl
        << "\% de valores ímpares: " << (100.00*aux2)/TAM << endl;
    
    // Soma e média
    aux = 0;
    for (int i = 0; i < TAM; i++) {
        aux += vet[i];
    }
    cout << "A soma dos elementos é " << aux << endl
        << "A média é " << aux/(TAM*1.00) << endl;
    return 0;
}
