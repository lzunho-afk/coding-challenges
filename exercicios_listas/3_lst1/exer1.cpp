/*
 * Construa um programa que:
 * a. Aloque dinamicamente um vetor de 10 posições;
 * b. Gravar as 10 posições do vetor com valores aleatório, intervalo de 20 a 50;
 * c. Mostre o vetor;
 * d. Libere a memória alocada.
*/

#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *p_vet = new int[10];
    cout << "Vetor => {\n";
    for (int i = 0; i < 10; i++) {
        *(p_vet + i) = rand() % 30 + 20;
        cout << "\t" << *(p_vet + i) << ",\n";
    }
    cout << "}\n";
    delete[] p_vet;
    return 0;
}
