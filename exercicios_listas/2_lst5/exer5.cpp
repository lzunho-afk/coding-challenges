/*
 * Crie um programa que receba um número inteiro qualquer menor que 999,
 * implemente uma função recursiva para realizar a soma dos algarismos que
 * compõem o número. Exemplo:
 *  Entrada 528
 *  Resultado: 15 (5 + 2 + 8)
 * Considere que o algarismo 0 (zero) não fará parte do número informado.
 */

#include <iostream>

using namespace std;

int alg_s(int n) {
    if (n/10 != 0) {
        return n%10 + alg_s(n/10);
    } else {
        return n;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    unsigned short n;

    cout << "Número > ";
    cin >> n;

    cout << "> A soma dos algarismos é " << alg_s(n) << endl;
    return 0;
}
