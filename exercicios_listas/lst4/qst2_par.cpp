/*
Escreva um programa que receba um n�mero qualquer e verifique se o n�mero lido � par, caso seja
execute a divis�o deste n�mero por 2, caso n�o seja par execute a soma deste n�mero com 5 mostrando
em qualquer condi��o o resultado na tela.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int n;
    double aux;

    std::cout << "Informe o n�mero: ";
    std::cin >> n;

    if (n % 2 == 0) {
        aux = n / 2;
    } else {
        aux = n + 5;
    }
    std::cout << aux << "\n";
    return 0;
}
