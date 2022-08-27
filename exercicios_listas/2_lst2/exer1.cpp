/*
 * Faça um programa que lê um texto qualquer do teclado, remova os espaços em
 * branco do texto e apresente o texto conforme lido, sem os espaços, e o 
 * texto de forma invertida, sem os espaços.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int count = 0;
    std::string text;

    std::cout << "Por favor, informe o texto: ";
    getline(std::cin, text);
    fflush(stdin);

    std::cout << "~> Texto sem espaços: ";
    for (int i = 0; i < text.size(); i++) {
        if (!isspace(text[i]))
            std::cout << text[i];
    }
    std::cout << std::endl;

    std::cout << "~> Ao contrário: ";
    for (int i = text.size()-1; i >= 0; i--) {
        if (!isspace(text[i]))
            std::cout << text[i];
    }
    std::cout << std::endl;
    return 0;
}
