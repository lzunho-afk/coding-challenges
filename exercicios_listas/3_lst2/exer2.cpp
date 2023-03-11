/*
 * Faça um programa que cadastre em uma estrutura do tipo pilha vários números, sendo no máximo 6, ao
 * remover um número desta estrutura o mesmo deve ser empilhado em outra pilha, conforme o critério:
 * se o número for par na pilha dos pares, se for ímpar na pilha dos ímpares. No menu de opções deve
 * ter uma alternativa para zerar as três pilhas, mostrar pilha inicial, a dos pares e a dos ímpares.
*/

#include <iostream>
#include <sstream>
#include <string>
#include "pilha_estatica.hpp"

#define MAX_TAM_STACK 6

using namespace std;

const char *menu = "\n### Distribuição - PAR/IMPAR ###\n"   \
                    "1 - Pop (distribuir)\n"                \
                    "2 - Mostrar pilha de origem\n"         \
                    "3 - Mostrar pares\n"                   \
                    "4 - Mostrar impares\n"                 \
                    "5 - Limpar e inserir novamente\n"      \
                    "0 - Sair\n"                            \
                    ": ";

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack<int> origin;
    Stack<int> pares;
    Stack<int> impares;
    string s;
    int tam, aux, val;

    origin.start_stack(MAX_TAM_STACK);
    pares.start_stack(MAX_TAM_STACK);
    impares.start_stack(MAX_TAM_STACK);

    cout << "### Inserção dos valores - MAX_" << MAX_TAM_STACK << " ###\n";
    int c = 0;
    cout << "\tValor " << c << ": ";
    while (getline(cin, s)) {
        if (stringstream(s) >> aux && c < 6) {
            origin.push_stack(aux);
        } else {
            break;
        }
        c++;
        cout << "\tValor " << c << ": ";
    }

    while (true) {
        cout << menu;
        cin >> aux;

        switch(aux) {
        case 1:
            val = origin.pop_stack();
            if (val % 2 == 0) {
                pares.push_stack(val);
            } else {
                impares.push_stack(val);
            }
            break;
        case 2:
            origin.show_stack();
            break;
        case 3:
            pares.show_stack();
            break;
        case 4:
            impares.show_stack();
            break;
        case 5:
            origin.make_stack_empty();
            pares.make_stack_empty();
            impares.make_stack_empty();

            cout << "----> Valores limpos... <----\n";
            cout << "### Inserção dos valores - MAX_" << MAX_TAM_STACK << " ###\n";
            c = 0;
            cout << "\tValor " << c << ": ";
            cin.ignore();
            while (getline(cin, s)) {
                if (stringstream(s) >> aux && c < 6) {
                    origin.push_stack(aux);
                } else {
                    break;
                }
                c++;
                cout << "\tValor " << c << ": ";
            }
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}
