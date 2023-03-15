/* pilha_dinamica.hpp -- exemplo simples de pilha dinâmica
 * MIT (c) Lucas Zunho <lucaszunho17@gmail.com>
*/

#ifndef PILHA_DINAMICA_HPP
#define PILHA_DINAMICA_HPP

#include <iostream>

typedef struct node {
    int data;
    struct node* nnext;
} Node;

typedef struct stack {
    Node* top;
} Stack;

// Inicia a pilha dinamica
void start_stack(Stack* stack) {
    stack->top = nullptr;
}

// Verifica se a pilha está vazia ou não
bool is_empty(Stack* p) {
    if (p->top == NULL) {
        return true;
    } else {
        return false;
    }
}

// Método Push
bool push(Stack* p, int data) {
    Node* nnew = new Node;
    if (nnew == NULL) {
        // Erro de alocação
        return false;
    }

    nnew->data = data;
    nnew->nnext = p->top;
    p->top = nnew;
    return true;
}

// Método Pop
int pop(Stack* p) {
    int data = 0;
    if (!is_empty(p)) {
        data = p->top->data;
        Node* ndel = p->top;
        p->top = p->top->nnext;

        delete ndel;
    }
    return data;
}

// Método Peek
int peek(Stack* p) {
    int data = 0;
    if (!is_empty(p)) {
        data = p->top->data;
    }
    return data;
}

// Dump das informações presentes na pilha
void show(Stack* p) {
    cout << "Stack dump:\n";

    if (!is_empty()) {
        cout << "--------------------------------------------\n";
        cout << setfill(' ') << std::setw(13) << "Node" << " | ";
        cout << setfill(' ') << std::setw(13) << "NNode" << " | ";
        cout << setfill(' ') << std::setw(10) << "Data" << " |\n";
        cout << "--------------------------------------------\n";
        Node *node = p->top;
        while (node != NULL)
        {
            cout << setfill(' ') << std::setw(13) << node << " | ";
            cout << setfill(' ') << std::setw(13) << node->nnext << " | ";
            cout << setfill(' ') << std::setw(10) << node->data << " |" << endl;

            node = node->nnext;
        }
        cout << "--------------------------------------------" << endl;
    }
}

// Destroi os dados presentes na pilha
void destroy(Stack* p) {
    int data;
    while(!is_empty(p)) {
        data = pop(p);
    }
}

#endif // PILHA_DINAMICA_HPP