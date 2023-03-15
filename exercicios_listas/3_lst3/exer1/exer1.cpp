/*
 * Empregando pilha, implemente um programa para inverter a ordem das letras nas
 * palavras em uma frase. Por exemplo, na frase “teste de pilha”, o programa
 * deverá exibir “etset ed ahlip”.
*/

#include <iostream>
#include "pilha_dinamica.hpp"

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack* p = new Stack();
    string uinput;
    cout << "Informe uma frase: ";
    getline(cin, uinput);

    for (int i = 0; i < uinput.size(); i++) {
        push(p, uinput[i]);
        if (uinput[i] == ' ') {
            pop(p);
            while (p->top != NULL) {
                cout << pop(p);
            }
            cout << ' ';
        }
        if (i == uinput.size()-1) {
            while (p->top != NULL) {
                cout << pop(p);
            }
        }
    }
    return 0;
}
