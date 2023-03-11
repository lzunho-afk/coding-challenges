/*
 * Crie uma pilha que permita armazenar dados do tipo string. Para isso, deve-se modificar a estrutura da Pilha,
 * “int *dados;” para “string *dados;”. Além disso, as demais funções que recebem o valor do tipo inteiro devem
 * ser alteradas para o tipo string.
*/

#include <iostream>
#include "pilha_estatica.hpp"

using namespace std;

const char *menu = "\n### Estrutura de Dados Pilha - String ###\n"  \
                    "0 - Criar pilha\n"                             \
                    "1 - Push\n"                                    \
                    "2 - Pop\n"                                     \
                    "3 - Peek\n"                                    \
                    "4 - Mostrar\n"                                 \
                    "5 - Consultar\n"                               \
                    "6 - Limpar pilha\n"                            \
                    "99 - Sair\n"                                   \
                    ": ";

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack<string> stack;
    int aux, val, tam;
    string sval;
    bool isstarted = false;

    // User stack tam input
    cout << "Informe o tamanho da pilha: ";
    cin >> tam;

    while (true) {
        cout << menu;
        cin >> aux;

        switch(aux) {
        case 0:
            isstarted = true;
            stack.start_stack(tam);
            break;
        case 1:
            if (isstarted) {
                cout << "> Valor (str): ";
                cin >> sval;

                // Verifica se o valor está presente na pilha
                if (!stack.top == stack.base) {
                    for (int i = stack.top; i > stack.base; i--) {
                        if (*(stack.p_node + i) == sval) {
                            cerr << "> Err. Valor já existe na pilha!\n";
                            break;
                        }
                    }
                }
                stack.push_stack(sval);
            } else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 2:
            if (isstarted)
                stack.pop_stack();
            else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 3:
            if (isstarted)
                stack.peek_stack();
            else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 4:
            if (isstarted)
                stack.show_stack();
            else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 5:
            if (isstarted) {
                cout << "> Posição: ";
                cin >> val;
                sval = stack.search_stack_pos(val);
                if (aux == -1) {
                    cerr << "> Posição não encontrada!\n";
                } else {
                    cout << "> O valor está presente na posição \"" << val << "\" é \"" << sval << "\"\n";
                }
            } else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 6:
            if (isstarted) {
                cout << "Limpando...\n";
                stack.make_stack_empty();
            } else {
                cerr << "Pilha não iniciada!\n";
            }
            break;
        case 99:
            return 0;
        default:
            cerr << "> Err. Informe um valor válido!\n";
            break;
        }
    }
    return 0;
}

