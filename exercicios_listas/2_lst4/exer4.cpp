/*
 * Crie um programa que manipule um vetor V[10] que deve ser preenchido 
 * com valores inteiros entre 15 e 50, sem números repetidos.
 * Após gerar o vetor o programa deverá:
 *  - Exibir o vetor na tela
 *  - Exibir o vetor em ordem crescente e decrescente
 *  - Exibir o percentual de valores pares e ímpares constantes no vetor
 *  - Exibir os elementos que se encontram em posições (índices) ímpares
 */

#include <iostream>

#define TAM 10
#define RAND_MN 15
#define RAND_MX 50

using namespace std;

void gen_vet(int vet[TAM]);
void show_vet(int vet[TAM], string vet_name);
void dcvet(int vet[TAM]);
void vet_per(int vet[TAM]);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int vet[TAM];
    
    // Geração de vetor
    gen_vet(vet);

    // Mostrar vetor
    show_vet(vet, "Vetor");

    // Mostrar vetor em ordem crescente e decrescente
    dcvet(vet);

    // Pares e Ímpares (percentual)
    vet_per(vet);

    // Elementos em índices ímpares
    cout << "> Elementos com índices ímpares => {" << endl;
    for (int i = 0; i < TAM; i++) {
        if (i != 0 && i % 2 != 0) {
            cout << "\tVet[" << i << "] => " << vet[i] << endl;
        }
    }
    cout << "}" << endl;
    return 0;
}

void vet_per(int vet[TAM]) {
    cout.precision(2);
    int c_pr, c_imp;
    c_pr = c_imp = 0;
    for (int i = 0; i < TAM; i++) {
        if (vet[i] % 2 == 0) {
            c_pr++;
        } else {
            c_imp++;
        }
    }
    cout << "> Percentual de valores pares: " << fixed << (c_pr*100.00)/TAM*1.00 << endl
        << "> Percentual de valores ímpares: " << fixed << (c_imp*100.00)/TAM*1.00 << endl;
}

void dcvet(int vet[TAM]) {
    string output("");
    int aux, avet[TAM];

    for (int i = 0; i < TAM; i++) {
        avet[i] = vet[i];
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (avet[i] < avet[j]) {
                aux = avet[i];
                avet[i] = avet[j];
                avet[j] = aux;
            }
        }
    }
    show_vet(avet, "Vet Crescente");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (avet[i] > avet[j]) {
                aux = avet[i];
                avet[i] = avet[j];
                avet[j] = aux;
            }
        }
    }
    show_vet(avet, "Vet Decrescente");
}

void show_vet(int vet[TAM], string vet_name) {
    cout << "> " << vet_name << "[" << TAM << "] => {";
    for (int i = 0; i < TAM; i++) {
        cout << vet[i];
        if (i + 1 != TAM) {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

void gen_vet(int vet[TAM]) {
    srand(time(NULL));
    int ns[RAND_MX-RAND_MN], ns_idx, aux, idx;

    ns_idx = 0;
    for (int i = RAND_MN; i < RAND_MX; i++) {
        ns[ns_idx] = i;
        ns_idx++;
    }

    for (int i = ns_idx - 1; i > 0; i--) {
        idx = rand() % (i + 1);
        aux = ns[idx];
        ns[idx] = ns[i];
        ns[i] = aux;
    }

    for (int i = 0; i < TAM; i++) {
        vet[i] = ns[i];
    }
}

