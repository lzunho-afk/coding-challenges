/*
 * Escreva um programa que apresente os primeiros 20 termos da sequência
 * de Fibonacci: “A geração n de Fibonacci retorna 1 quando for até a 2a
 * geração. Se não, retorna a soma das duas últimas gerações anteriores”.
 * Utilize uma função recursiva para resolver este problema.
 */

#include <iostream>
#include <vector>

#define FIB_LEN 20

using namespace std;

const char* header = "## Sequência de Fibonacci ##\n";

vector <unsigned long long int> fib_n(21, 77);

unsigned long long int fib(int n) {
    if (fib_n[n] == 77) {
        if (n < 2) {
            return fib_n[n];
        } else {
            fib_n[n] = fib(n-1) + fib(n-2);
            return (fib_n[n]);
        }
    } else {
        return fib_n[n];
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    unsigned long long int a;

    cout << header << "-- " << FIB_LEN << " Termos --" << endl;
    
    fib_n[0] = 0;
    fib_n[1] = 1;
    a = fib(FIB_LEN);
    for (int i = 0; i < FIB_LEN; i++) {
        cout << "Fib[" << i << "] ~> " << fib_n[i] << endl;
    }
    return 0;
}
