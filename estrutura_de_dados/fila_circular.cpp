#include <iostream>
#include "fila_circular.hpp"

using namespace std;

typedef int TEMPLATE_PRIMITIVE;

const char* menu =  "## Fila Circular ##\n" \
                    "1 - Inicializar fila\n"\
                    "2 - Destruir fila\n"   \
                    "3 - Visualizar fila\n" \
                    "4 - Enfileirar\n"      \
                    "5 - Desenfileirar\n"   \
                    "0 - Sair\n"            \
                    ": ";

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    CircularQueue<TEMPLATE_PRIMITIVE> queue;
    TEMPLATE_PRIMITIVE aux;
    int es;

    while (true) {
        cout << menu;
        cin >> es;

        switch(es) {
            case 0:
                cout << "Saindo...\n";
                return 0;
            case 1:
                cout << "> Informe o tamanho da fila: ";
                cin >> es;
                queue.start(es);
                break;
            case 2:
                queue.destroy();
                break;
            case 3:
                queue.show();
                break;
            case 4:
                cout << "> Informe o valor a ser enfileirado: ";
                cin >> aux;
                queue.push(aux);
                break;
            case 5:
                aux = queue.pop();
                cout << "> Valor \"" << aux << "\" desenfileirado!\n";
                break;
            default:
                cout << "> Opção inválida! Tente novamente...\n";
                break;
        }
    }
    return 0;
}
