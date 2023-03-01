#include <iostream>
#include "pilha_estatica.hpp"

using namespace std;

const char *menu = "\n### Estrutura de Dados Pilha ###\n"   \
                    "1 - Push\n"                            \
                    "2 - Pop\n"                             \
                    "3 - Peek\n"                            \
                    "4 - Mostrar\n"                         \
                    "5 - Consultar\n"                       \
                    "6 - Limpar pilha\n"                    \
                    "0 - Sair\n"                            \
                    ": ";

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Stack* p_stack = new Stack;
    int aux, val;

    // User stack tam input
    cout << "Informe o tamanho da pilha: ";
    cin >> aux;
    start_stack(p_stack, aux);

    while (true) {
        cout << menu;
        cin >> aux;

        switch(aux) {
        case 1:
            cout << "> Valor: ";
            cin >> val;
            push_stack(p_stack, val);
            break;
        case 2:
            pop_stack(p_stack);
            break;
        case 3:
            peek_stack(p_stack);
            break;
        case 4:
            show_stack(p_stack);
            break;
        case 5:
            cout << "\n1 - Por posição\n2 - Por valor\n: ";
            cin >> aux;
            switch(aux) {
            case 1:
                cout << "> Posição: ";
                cin >> val;
                aux = search_stack_pos(p_stack, val);
                if (aux == -1) {
                    cerr << "> Posição não encontrada!\n";
                } else {
                    cout << "> O valor está presente na posição \"" << val << "\" é \"" << aux << "\"\n";
                }
                break;
            case 2:
                cout << "> Valor: ";
                cin >> val;
                aux = search_stack_val(p_stack, val);
                if (aux == -1) {
                    cerr << "> Valor não encontrado!\n";
                } else {
                    cout << "Valor encontrado na posição \"" << aux << "\"\n";
                }
                break;
            }
            break;
        case 6:
            cout << "Limpando...\n";
            make_stack_empty(p_stack);
            break;
        case 0:
            return 0;
        default:
            cerr << "> Err. Informe um valor válido!\n";
            break;
        }
    }
    return 0;
}
