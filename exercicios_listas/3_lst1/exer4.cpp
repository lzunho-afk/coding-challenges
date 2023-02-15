/*
 * Faça um programa que crie dinamicamente um vetor de n elementos e passe esse vetor
 * para uma função que vai ler os elementos desse vetor. Depois, no programa principal
 * (main), o vetor preenchido deve ser impresso. Além disso, antes de finalizar o programa,
 * deve-se liberar a área de memória alocada.
 */

#include <iostream>
#include <ctime>

using namespace std;

void get_vet(int *p_vet, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Vet[" << i << "] => ";
        cin >> *(p_vet + i);
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int n;
    int* p_vet;

    cout << "Informe o tamanho do vetor (0 para aleatório): ";
    cin >> n;
    if (n == 0) n = rand() % 1000;
    p_vet = new int[n];

    get_vet(p_vet, n);

    cout << "\nVetor => {\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << *(p_vet + i) << ",\n";
    }
    cout << "}\n";

    delete[] p_vet;
    return 0;
}
