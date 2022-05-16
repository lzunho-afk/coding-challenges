/*
Elabore um algoritmo que receba um ano (numérico inteiro) e informe se o ano é bissexto ou não.
Lembrete:
São bissextos todos os anos múltiplos de 400, ex.: 1600, 2000, 2400, 2800...
São bissextos todos os múltiplos de 4 e não múltiplos de 100, ex.: 1996, 2004, 2008, 2012, 2016...
Não são bissextos todos os demais anos.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int ano, aux;
    std::cout << "Por favor, informe o ano: ";
    std::cin >> ano;

    aux = ano % 400;
    if ((aux == 0) || (aux % 4 == 0) && (ano % 100 != 0)) {
        std::cout << ano << " É um ano bissexto!\n";
    } else {
        std::cout << ano << " NÃO é um ano bissexto\n";
    }
    return 0;
}
