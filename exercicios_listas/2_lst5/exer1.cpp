/*
 * Crie um programa que implemente uma função recursiva para calcular o MDC
 * (Máximo Divisor Comum) entre dois números inteiros e positivos. Para 
 * calcular o MDC deve-se utilizar o algoritmo de Euclides, que possui como
 * conceito: “O MDC de dois números inteiros é o maior número inteiro que 
 * divide ambos sem deixar resto”.
 */

#include <iostream>

using namespace std;

int mdc(int n1, int n2) {
    if (n2 == 0)
        return n1;
    else
        return mdc(n2, n1%n2);
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;

    cout << "Informe o número 1: ";
    cin >> n1;
    cout << "Informe o número 2: ";
    cin >> n2;

    cout << "O MDC de " << n1 << " e " << n2 << " é " << mdc(n1, n2) << endl;
    return 0;
}
