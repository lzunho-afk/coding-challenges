/*
 * Implemente um programa que manipule uma pilha. O programa deve ser desenvolvido com as seguintes regras:
 * - Criar um menu com as op��es:
 *     * Criar pilhar - O usu�rio deve informar o tamanho da pilha; caso a pilha j� tenha sido criada
 * anteriormente, antes de criar uma pilha nova, a pilha antiga deve ser removida e a mem�ria deve
 * ser desalocada.
 *     * Inserir - O usu�rio deve informar um valor a ser inserido; caso a pilha esteja cheia, uma mensagem
 * deve ser exibida.
 *     * Remover - Remover um elemento da pilha e mostrar o elemento removido; caso a pilha esteja
 * vazia, uma mensagem deve ser exibida.
 *     * Consultar - Verificar se a pilha cont�m um determinado valor informado pelo usu�rio.
 *     * Mostrar - Mostar a pilha.
 *     * Sair - Sair do programa.
 * - N�o permitir a inclus�o de valores duplicados;
 * - Imprimir uma mensagem de erro caso a pilha n�o tenha sido criada e o usu�rio tente executar uma das
 * seguintes opera��es: inserir, remover, consultar ou mostrar
*/

#include <iostream>
#include "pilha_estatica.hpp"

using namespace std;

const char *menu = "\n### Estrutura de Dados Pilha ###\n"   \
                    "0 - Criar pilha\n"                     \
                    "1 - Push\n"                            \
                    "2 - Pop\n"                             \
                    "3 - Peek\n"                            \
                    "4 - Mostrar\n"                         \
                    "5 - Consultar\n"                       \
                    "6 - Limpar pilha\n"                    \
                    "99 - Sair\n"                           \
                    ": ";

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack<int> stack;
    int aux, val, tam;
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
                cout << "> Valor: ";
                cin >> val;

                // Verifica se o valor est� presente na pilha
                aux = 0;
                if (!stack.top == stack.base) {
                    for (int i = stack.top; i > stack.base; i--) {
                        if (*(stack.p_node + i) == val) {
                            aux = 1;
                        }
                    }
                }
                if (!aux) {
                    stack.push_stack(val);
                } else {
                    cerr << "> Err. Valor j� existe na pilha!\n";
                }
            } else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 2:
            if (isstarted)
                stack.pop_stack();
            else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 3:
            if (isstarted)
                stack.peek_stack();
            else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 4:
            if (isstarted)
                stack.show_stack();
            else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 5:
            if (isstarted) {
                cout << "> Posi��o: ";
                cin >> val;
                aux = stack.search_stack_pos(val);
                if (aux == -1) {
                    cerr << "> Posi��o n�o encontrada!\n";
                } else {
                    cout << "> O valor est� presente na posi��o \"" << val << "\" � \"" << aux << "\"\n";
                }
            } else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 6:
            if (isstarted) {
                cout << "Limpando...\n";
                stack.make_stack_empty();
            } else {
                cerr << "Pilha n�o iniciada!\n";
            }
            break;
        case 99:
            return 0;
        default:
            cerr << "> Err. Informe um valor v�lido!\n";
            break;
        }
    }
    return 0;
}

