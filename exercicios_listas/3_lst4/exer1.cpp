/*
 * Desenvolva um programa que permita gerenciar uma pista para descolagem de aviões de um aeroporto.
 * Para o correto funcionamento desta pista é necessário que seja implementada uma fila com as 
 * seguintes funcionalidades:
 *  a) No de aviões à espera de decolar.
 *  b) Entrada de um novo avião para decolar (incluir na fila).
 *  c) Descolagem de um avião (retirar da fila).
 *  d) Listar todos os aviões à espera para decolagem (mostrar fila).
 *  e) Listar as características do próximo avião a decolar (peek).
 *  Observação: para cada avião são necessárias as seguintes informações: código do avião, número de
 *  passageiros, empresa.
*/

#include <iostream>

using namespace std;

const char* menu = "### Menu Aeroporto ###\n"               \
                   "1) Mostrar avioes em espera\n"          \
                   "2) Registrar pouso de Aviao\n"          \
                   "3) Registrar decolagem de aviao\n"      \
                   "4) Mostrar proximo aviao a decolar\n"   \
                   "5) Retirar todos os avioes (limpar)\n"  \
                   "0) Sair\n"                              \
                   ": ";

typedef struct node {
    int code;
    int passengers_count;
    string company;
} Aviao;

struct Queue {
    int size;
    int total;
    int end;
    int start;
    Aviao* node;

    Queue() {
        size = 0;
        total = 0;
        end = 0;
        start = 0;
        node = nullptr;
    }

    void reset() {
        size = 0;
        total = 0;
        end = 0;
        start = 0;

        if (node != NULL) {
            delete[] (this->node);
            this->node = nullptr;
        }
    }
};

void start_queue(Queue *q, int size) {
    q->size = size;
    q->start = 0;
    q->end = 0;
    q->total = 0;

    // Nó de avião
    q->node = new Aviao[size];
}

bool is_queue_empty(Queue* q) {
    if (q->total == 0) {
        return true;
    } else {
        return false;
    }
}

bool is_queue_filled(Queue* q) {
    if (q->total == q->size) {
        return true;
    } else {
        return false;
    }
}

void plane_info(Aviao* plane, string header) {
    cout << header << " {\n"
        << "\tCodigo => " << plane->code << '\n'
        << "\tQt. Passageiros => " << plane->passengers_count << '\n'
        << "\tCompanhia => " << plane->company << '\n'
        << "}\n";
}

void waiting_list(Queue* q) {
    if (!is_queue_empty(q)) {
        int idx = q->start;
        cout << "-> Avioes em Espera:\n";
        for (int i = 0; i < q->total; i++) {
            plane_info(&(q->node[idx]), "Aviao " + to_string(idx));
            if (i < q->total-1) {
                cout << ",";
            }
            idx++;
            if (idx >= q->size) {
                idx = 0;
            }
            cout << '\n';
        }
        cout << '\n';
    } else {
        cout << "-> Nenhum aviao em espera!\n";
    }
}

bool reg_landing(Queue* q, Aviao* node) {
    if (q->node == NULL) {
        cerr << "-> Err. Fila Estatica nao inicializada!\n";
        return false;
    }
    if (is_queue_filled(q)) {
        cerr << "-> O aeroporto esta cheio!!!\n";
        return false;
    }

    // Adiciona membro e ajusta a fila
    q->node[q->end] = *node;
    q->total++;
    q->end++;

    if (q->end >= q->size) {
        q->end = 0;
    }
    return true;
}

Aviao *reg_dec(Queue* q) {
    if (is_queue_empty(q)) {
        cerr << "-> Nao ha avioes para decolagem\n";
        return nullptr;
    }
    
    // Remove membro e ajusta a fila
    Aviao *node = new Aviao();
    node = &(q->node[q->start]);
    q->total--;
    q->start++;
    
    if (q->start >= q->size) {
        q->start = 0;
    }
    return node;
}

Aviao *next_dec(Queue* q) {
    if (is_queue_empty(q)) {
        return nullptr;
    }

    // Peek
    Aviao *node = new Aviao();
    node = &(q->node[q->start]);
    return node;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    Queue* queue = new Queue();
    Aviao* aux_node = nullptr;
    int land_sp;

    // Entrada do tamanho da fila
    cout << "-> Informe a quantidade de avioes suportados pelo aeroporto: ";
    cin >> land_sp;
    start_queue(queue, land_sp);

    // Menu loop
    int es;
    while (true) {
        cout << menu;
        cin >> es;

        switch (es) {
            case 0:
                queue->reset();
                return 0;
            case 1:
                waiting_list(queue);
                break;
            case 2:
                // Entrada das informações
                aux_node = new Aviao();
                cout << "\n-> Codigo do aviao: ";
                cin >> aux_node->code;
                cout << "-> Numero de passageiros: ";
                cin >> aux_node->passengers_count;
                cout << "-> Nome da empresa: ";
                cin >> aux_node->company;

                // Operação de registro
                if (reg_landing(queue, aux_node)) {
                    plane_info(aux_node, "POUSO");
                }
                break;
            case 3:
                aux_node = reg_dec(queue);
                plane_info(aux_node, "DECOLAGEM");
                break;
            case 4:
                aux_node = next_dec(queue);
                if (aux_node != nullptr) {
                    plane_info(aux_node, "PROXIMA DECOLAGEM");
                }
                break;
            case 5:
                queue->reset();

                // Entrada do tamanho da fila
                cout << "-> Informe a quantidade de avioes suportados pelo aeroporto: ";
                cin >> land_sp;
                start_queue(queue, land_sp);
                break;
            default:
                cerr << "-> Opcao de entrada invalida!\n";
                break;
        }
    }
    return 0;
}
