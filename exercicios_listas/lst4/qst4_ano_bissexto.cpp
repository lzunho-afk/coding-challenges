/*
Elabore um algoritmo que receba um ano (num�rico inteiro) e informe se o ano � bissexto ou n�o.
Lembrete:
S�o bissextos todos os anos m�ltiplos de 400, ex.: 1600, 2000, 2400, 2800...
S�o bissextos todos os m�ltiplos de 4 e n�o m�ltiplos de 100, ex.: 1996, 2004, 2008, 2012, 2016...
N�o s�o bissextos todos os demais anos.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int ano, aux;
    std::cout << "Por favor, informe o ano: ";
    std::cin >> ano;

    aux = ano % 400;
    if ((aux == 0) || (aux % 4 == 0) && (ano % 100 != 0)) {
        std::cout << ano << " � um ano bissexto!\n";
    } else {
        std::cout << ano << " N�O � um ano bissexto\n";
    }
    return 0;
}
