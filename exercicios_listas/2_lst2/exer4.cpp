/*
 * Escreva um programa que leia 3 strings quaisquer em seguida verifique, em 
 * relação ao número de caracteres, qual é a maior string, a menor string e 
 * a do meio, apresente as string em ordem crescente em relação ao número de
 * caracteres que possuem e com todos os caracteres em maiúsculo.
 */

#include <iostream>

using namespace std;

string toupper_str(string str) {
    for (int i = 0; i <= str.size(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    string maior, meio, menor, aux;
    string str[3];

    for (int i = 0; i < 3; i++) {
        cout << "Informe a linha " << i+1 << ": ";
        getline(cin, str[i]);
        fflush(stdin);
    }

    maior = str[0];
    meio = str[1];
    menor = str[2];
    if (maior.size() < meio.size()) {
        aux = maior;
        maior = meio;
        meio = aux;
    }
    if (maior.size() < menor.size()) {
        aux = maior;
        maior = menor;
        menor = aux;
    }
    if (meio.size() < menor.size()) {
        aux = meio;
        meio = menor;
        menor = aux;
    }

    cout << "~> MAIOR: " << toupper_str(maior) << endl
        << "~> MEIO: " << toupper_str(meio) << endl
        << "~> MENOR: " << toupper_str(menor) << endl;
    return 0;
}
