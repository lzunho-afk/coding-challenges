/*
Escreva uma fun��o que manipule no programa principal um vetor de 10 posi��es de
inteiros, dever� ser implementado as seguintes fun��es:
- Fun��o para preencher o vetor com n�meros aleat�rios entre 25 e 75
- Fun��o para mostrar o vetor na tela
- Fun��o para ordenar os elementos do vetor em ordem decrescente
- Fun��o que dever� retornar a m�dia dos elementos do vetor
*/

#include <iostream>

#define TAM 10

using namespace std;

void set_vet(int *vet);
void mostra_vet(char* hname, int *vet);
void ord_decrescente(int *vet);
double med_vet(int *vet);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    cout.precision(2);

    int vet[TAM];
    double med;

    set_vet(vet);
    mostra_vet("vet", vet);

    ord_decrescente(vet);
    mostra_vet("decrescente", vet);

    cout << "A m�dia dos elementos �: " << fixed << med_vet(vet) << endl;

    return 0;
}

void set_vet(int *vet) {
    for (int i = 0; i < TAM; i++) {
        vet[i] = (rand() % 50) + 25;
    }
}

void mostra_vet(char* hname, int *vet) {
    cout << hname << " {" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\tn:" << i << " ~> " << vet[i] << endl;
    }
    cout << "}" << endl;
}

void ord_decrescente(int *vet) {
    int aux;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

double med_vet(int *vet) {
    int count, soma;
    count = soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += vet[i];
        count++;
    }
    return (soma * 1.00/count);
}
