/*
 * Escreva um programa que receba um texto qualquer do teclado, em seguida
 * apresente:
 * - Total de caracteres do texto
 * - Total de espaços em branco
 * - Total de vogais
 * - Total de consoantes
 * - Total de números
 * - Total de caracteres especiais
 */

#include <iostream>

using namespace std;

bool isvogal(char lt) {
    string vogais("aeiou");
    for (int i = 0; i < 5; i++) {
        if (vogais[i] == lt) {
            return true;
        }
    }
    return false;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int t_ch, sp, vog, con, num, esp_ch;
    string text;

    cout << "Por favor, informe o texto: ";
    getline(cin, text);
    fflush(stdin);

    t_ch = text.size();
    sp = vog = con = num = esp_ch = 0;
    for (int i = 0; i < t_ch; i++) {
        if (isalnum(text[i])) {
            if (isalpha(text[i])) {
                if (isvogal(text[i])) {
                    vog++;
                } else {
                    con++;
                }
            } else if (isdigit(text[i])) {
                num++;
            }
        } else if (isspace(text[i])) {
            sp++;
        } else {
            esp_ch++;
        }
    }

    cout << "\t-> Caracteres: " << t_ch << endl
        << "\t-> Espaços em branco: " << sp << endl
        << "\t-> Vogais: " << vog << endl
        << "\t-> Consoantes: " << con << endl
        << "\t-> Números: " << num << endl
        << "\t-> Caracteres Especiais: " << esp_ch << endl;
    return 0;
}
