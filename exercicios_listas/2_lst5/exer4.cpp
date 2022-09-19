/*
 * Crie um programa que calcula o n-ésimo número harmônico que é calculado 
 * pela seguinte fórmula:
 *  H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >= 1). Escreva uma 
 *  função recursiva que calcula H(n).
 */

#include <iostream>

using namespace std;

double harx(int n) {
    if (n == 1) {
        return 1.00;
    } else {
        return (1.00/n + harx(n-1));
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);
    unsigned int input;
    
    cout << "Número > ";
    cin >> input;

    cout << "> O termo harmônico de número " << input << " é " << fixed << harx(input) << endl;
    return 0;
}
