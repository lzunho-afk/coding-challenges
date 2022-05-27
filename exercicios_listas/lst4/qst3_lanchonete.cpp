/*
Na lanchonete de Bianca são servidos três tipos de lanches, que são apresentados na tabela abaixo:

Código      : 10 / 11 / 12
Descrição   : Hambúrguer / Cachorro Quente / Torrada Simples
Valor       : 5.00 / 3.20 / 4.50

Crie um algoritmo que receba o código do produto e mostre na tela a descrição do mesmo e o seu
referido valor.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int code;
    std::string msg;
    std::cout << "Por favor, informe o código do produto: ";
    std::cin >> code;

    switch (code) {
    case 10:
        msg = "Hambúrguer : 5.00";
        break;
    case 11:
        msg = "Cachorro Quente : 3.20";
        break;
    case 12:
        msg = "Torrada Simples : 4.50";
        break;
    default:
        msg = "Código invalido!!";
        break;
    }
    std::cout << msg << "\n";
    return 0;
}
