/*
 * Escrever um programa que recebe um texto qualquer e um caracter qualquer,
 * em seguida mostre o texto conforme lido, em seguida remova todas as 
 * ocorrências do caracter lido do texto e apresente o texto resultante
*/

#include <iostream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    string text;
    char ch;

    cout << "Texto: ";
    getline(cin, text);
    fflush(stdin);

    cout << "Caractere: ";
    cin >> ch;

    cout << "~> Texto sem ocorrências de '" << ch << "': \"";
    for (int i = 0; i < text.size(); i++) {
        if (!(text[i] == ch)) {
            cout << text[i];
        }
    }
    cout << "\"" << endl;
    return 0;
}
