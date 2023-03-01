#ifndef PILHA_ESTATICA_HPP
#define PILHA_ESTATICA_HPP

#include <iostream>
#include <iomanip>

using namespace std;

typedef int Node;

typedef struct stack {
    Node* p_node;
    int top;
    int tam;
    int base;
} Stack;

// Reseta pilha
void make_stack_empty(Stack* p_stack) {
    p_stack->p_node = new Node[p_stack->tam];
    p_stack->top = -1;
    p_stack->base = -1;
}

// Start da pilha
void start_stack(Stack* p_stack, int tam) {
    p_stack->tam = tam;
    make_stack_empty(p_stack);
}

bool push_stack(Stack* p_stack, int n) {
    int aux;
    if (p_stack->top == p_stack->tam - 1) {
        cerr << "> Err. Pilha cheia\n";
        return false;
    }
    p_stack->top++;
    *(p_stack->p_node + p_stack->top) = n;
    return true;
}

int pop_stack(Stack* p_stack) {
    int aux;
    if (p_stack->top == p_stack->base) {
        cerr << "> Err. Pilha vazia\n";
    }
    aux = *(p_stack->p_node + p_stack->top);
    p_stack->top--;
    return aux;
}

bool peek_stack(Stack* p_stack) {
    if (p_stack->top == p_stack->base) {
        cerr << "> Não há valores na pilha!\n";
        return false;
    }
    cout << "O elemento presente no topo é \"" << *(p_stack->p_node + p_stack->top) << "\"\n";
    return true;
}

bool isempty_stack(Stack* p_stack) {
    if (p_stack->top == p_stack->base) return true;
    else return false;
}

void show_stack(Stack* p_stack) {
    if(!isempty_stack(p_stack)) {
        cout << "   ------------" << endl;
        for(int i = p_stack->top; i > p_stack->base; i--){
            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << *(p_stack->p_node + i) << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}

// Retorna o VALOR da posição passada como argumento
int search_stack_pos(Stack* p_stack, int pos) {
    if (pos > p_stack->base && pos <= p_stack->top) {
        pos = *(p_stack->p_node + pos);
        return pos;
    }
    return -1;
}

// Retorna a POSIÇÃO do valor passado como argumento
bool search_stack_val(Stack* p_stack, int* val) {
    if (!isempty_stack(p_stack)) {
        for (int i = p_stack->top; i > p_stack->base; i--) {
            if (*(p_stack->p_node + i) == *val) {
                *val = i;
                return true;
            }
        }
    }
    return false;
}

#endif // PILHA_ESTATICA_HPP
