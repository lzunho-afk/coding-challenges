/*
Escreva um programa que receba um número qualquer e verifique se o número lido é par, caso seja
execute a divisão deste número por 2, caso não seja par execute a soma deste número com 5 mostrando
em qualquer condição o resultado na tela.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int n;
    double aux;

    std::cout << "Informe o número: ";
    std::cin >> n;

    if (n % 2 == 0) {
        aux = n / 2;
    } else {
        aux = n + 5;
    }
    std::cout << aux << "\n";
    return 0;
}
