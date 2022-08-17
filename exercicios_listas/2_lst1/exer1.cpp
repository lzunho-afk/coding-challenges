#include <iostream>
#include <cmath>

#define TAM 10

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    cout.precision(2);

    float vet_a[TAM], aux;

    cout << fixed;
    cout << "Vet_A => {" << endl;
    for(int i = 0; i < TAM; i++) {
        vet_a[i] = (rand() % 50) * 1.145;
        cout << "\t" << i << ": " << vet_a[i] << endl;
    }
    cout << "}" << endl;

    // Ordenação (crescente)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (vet_a[i] < vet_a[j]) {
                aux = vet_a[j];
                vet_a[j] = vet_a[i];
                vet_a[i] = aux;
            }
        }
    }

    // Mostra vetor arrendondado pra CIMA
    cout << "Vet_A(ceil) => {" << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "\t" << i << ": " << int(ceil(vet_a[i])) << endl;
    }
    cout << "}\n\n";

    // Mostra vetor arrendondado pra BAIXO
    cout << "Vet_A(floor) => {" << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "\t" << i << ": " << int(floor(vet_a[i])) << endl;
    }
    cout << "}\n\n";

    // Mostra vetor arrendondado através da PRIMEIRA CASA DECIMAL
    cout << "Vet_A(round) => {" << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "\t" << i << ": " << int(round(vet_a[i])) << endl;
    }
    cout << "}\n\n";
    return 0;
}
