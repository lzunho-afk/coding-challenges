/*
 * Elabore um programa que possibilite a realização dos seguintes 
 * cálculos:
 *  1 – Potenciação (entrada dois valores inteiros e positivos)
 *  2 – Raiz quadrada (entrada um valor inteiro e positivo)
 *  3 - Arredondar o valor seguindo o critério da primeira casa 
 *      decimal e mostrar na tela (entrada um valor float)
 *  4 – Verificar se um valor é primo ou não (entrada um valor 
 *      inteiro positivo)
 *  5 – Verificar se um valor é um número perfeito ou não (entrada
 *      um valor inteiro positivo).
 * O sistema deverá apresentar um menu com as opções e conforme a
 * opção desejada será solicitado os dados de entrada.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int es, n1, n2, aux;
    float n;

    do { 
        cout << "1 - Potenciação" << endl
            << "2 - Raiz quadrada" << endl
            << "3 - Arredondar (1ra casa decimal)" << endl
            << "4 - Verificar se é primo" << endl
            << "5 - Verificar se é perfeito" << endl
            << "0 - Sair" << endl << ":";
        cin >> es;

        switch(es) {
            case 1:
                cout << "N1 > ";
                cin >> n1;
                cout << "N2 > ";
                cin >> n2;
                aux = n1;
                for (int i = 1; i < n2; i++) {
                    aux *= n1;
                }
                cout << n1 << "^" << n2 << "=" << aux << endl;
                break;
            case 2:
                cout << "N > ";
                cin >> n1;
                cout << "sqrt(" << n1 << ")=" << sqrt(n1) << endl;
                break;
            case 3:
                cout << "N > ";
                cin >> n;
                cout << "res => " << round(n) << endl;
                break;
            case 4:
                cout << "N > ";
                cin >> n1;
                aux = 0;
                for (int i = 1; i <= n1; i++) {
                    if (n1 % i == 0) {
                        aux += 1;
                    }
                }
                if (aux == 2) {
                    cout << "res => O número É primo" << endl; 
                } else {
                    cout << "res => O número NÃO é primo" << endl;
                }
                break;
            case 5:
                cout << "N > ";
                cin >> n1;
                aux = 0;
                for (int i = 1; i < n1; i++) {
                    if (n1 % i == 0) {
                        aux += i;
                    }
                }
                if (aux == n1) {
                    cout << "res => O número É perfeito" << endl;
                } else {
                    cout << "res => O número NÃO é perfeito" << endl;
                }
                break;
            default:
                break;
        }
    } while (es != 0);
    return 0;
}
