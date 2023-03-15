#ifndef PILHA_ESTATICA_HPP
#define PILHA_ESTATICA_HPP

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct Stack {
    T *p_node;
    int top;
    int tam;
    int base;

    // Reseta pilha
    void make_stack_empty() {
        this->p_node = new T[this->tam];
        this->top = -1;
        this->base = -1;
    }

    // Start da pilha
    void start_stack(int tam) {
        this->tam = tam;
        make_stack_empty();
    }

    bool push_stack(T n) {
        if (this->top == this->tam - 1) {
            cerr << "> Err. Pilha cheia\n";
            return false;
        }
        this->top++;
        *(this->p_node + this->top) = n;
        return true;
    }

    T pop_stack() {
        T aux;
        if (this->top == this->base) {
            cerr << "> Err. Pilha vazia\n";
        }
        aux = *(this->p_node + this->top);
        this->top--;
        return aux;
    }

    bool peek_stack() {
        if (this->top == this->base) {
            cerr << "> Não há valores na pilha!\n";
            return false;
        }
        cout << "O elemento presente no topo é \"" << *(this->p_node + this->top) << "\"\n";
        return true;
    }

    void show_stack() {
        if(!(this->top == this->base)) {
            cout << "   ------------" << endl;
            for(int i = this->top; i > this->base; i--){
                cout << setfill(' ') << std::setw(3) << i << "|";
                cout << setfill(' ') << std::setw(10) << *(this->p_node + i) << "|" << endl;
                cout << "   ------------" << endl;
            }
        }
    }

    // Retorna o VALOR da posição passada como argumento
    T search_stack_pos(int pos) {
        T aux;
        if (pos > this->base && pos <= this->top) {
            aux = *(this->p_node + pos);
            return aux;
        }
        return NULL;
    }
};

#endif // PILHA_ESTATICA_HPP
