/*
 *  Faça um programa que receba dois valores inteiros e positivos, 
 *  referentes a uma base e um expoente, após crie uma função recursiva
 *  para realizar o cálculo e retornar o valor resultante.
 */

#include <iostream>

using namespace std;

long long int calc_exp(int b, int e, int buffer) {
    if (e == 0) {
        return 1;
    } else if (e != 1) {
        return calc_exp(b, e - 1, (b * buffer));
    } else {
        return buffer;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;

    cout << "Base (n1) > ";
    cin >> n1;
    cout << "Expoente (n2) > ";
    cin >> n2;

    cout << n1 << " elevado na " << n2 << " é " << calc_exp(n1, n2, n1) << endl;
    return 0;
}

