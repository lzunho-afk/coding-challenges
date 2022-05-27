/*
Na lanchonete de Bianca s�o servidos tr�s tipos de lanches, que s�o apresentados na tabela abaixo:

C�digo      : 10 / 11 / 12
Descri��o   : Hamb�rguer / Cachorro Quente / Torrada Simples
Valor       : 5.00 / 3.20 / 4.50

Crie um algoritmo que receba o c�digo do produto e mostre na tela a descri��o do mesmo e o seu
referido valor.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int code;
    std::string msg;
    std::cout << "Por favor, informe o c�digo do produto: ";
    std::cin >> code;

    switch (code) {
    case 10:
        msg = "Hamb�rguer : 5.00";
        break;
    case 11:
        msg = "Cachorro Quente : 3.20";
        break;
    case 12:
        msg = "Torrada Simples : 4.50";
        break;
    default:
        msg = "C�digo invalido!!";
        break;
    }
    std::cout << msg << "\n";
    return 0;
}
