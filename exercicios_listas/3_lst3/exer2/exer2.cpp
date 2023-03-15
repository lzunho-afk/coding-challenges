/* Empregando pilha, construa um programa para ordenar uma sequ�ncia de valores
 * inteiros fornecidos pelo usu�rio. Fa�a uso de duas pilhas: ORD e AUX. O objetivo
 * � organizar a pilha ORD de modo que nenhum item seja empilhado sobre outro menor,
 * fazendo uso da pilha auxiliar AUX.
 *  a) O usu�rio pode informar quantos valores inteiros ele desejar.
 *  b) Ao final, o programa deve mostrar a pilha ORD.
 */

#include <iostream>
#include "pilha_dinamica.hpp"

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack* ord = new Stack();
    Stack* aux = new Stack();
    int c, naux;
    string s;

    cout << "### Inser��o dos valores ###\n";
    c = 0;
    cout << "\tValor " << c << ": ";
    while (getline(cin, s)) {
        if (stringstream(s) >> naux) {
            while (!is_empty_stack(ord) && peek(ord) < naux) {
                push(aux, pop(ord));
            }
            push(ord, naux);
            while (aux->top != NULL) {
                push(ord, pop(aux));
            }
        } else {
            break;
        }
        c++;
        cout << "\tValor " << c << ": ";
    }

    show(ord);
    return 0;
}
