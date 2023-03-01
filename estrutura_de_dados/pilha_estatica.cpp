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
            cout << "\n1 - Por posi��o\n2 - Por valor\n: ";
            cin >> aux;
            switch(aux) {
            case 1:
                cout << "> Posi��o: ";
                cin >> val;
                aux = search_stack_pos(p_stack, val);
                if (aux == -1) {
                    cerr << "> Posi��o n�o encontrada!\n";
                } else {
                    cout << "> O valor est� presente na posi��o \"" << val << "\" � \"" << aux << "\"\n";
                }
                break;
            case 2:
                cout << "> Valor: ";
                cin >> val;
                aux = search_stack_val(p_stack, val);
                if (aux == -1) {
                    cerr << "> Valor n�o encontrado!\n";
                } else {
                    cout << "Valor encontrado na posi��o \"" << aux << "\"\n";
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
            cerr << "> Err. Informe um valor v�lido!\n";
            break;
        }
    }
    return 0;
}
