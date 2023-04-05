/*
 * Fila circular com o uso da funcionalidade de templates do c++.
*/

#ifndef FILA_ESTATICA_HPP
#define FILA_ESTATICA_HPP

#include <iostream>
#include <iomanip>

using namespace std;

template <typename DataType> struct CircularQueue {
    int size;
    int total;
    int init;
    int end;
    DataType* data;

    CircularQueue() {
        size = 0;
        total = 0;
        init = 0;
        end = 0;
        data = nullptr;
    }

    ~CircularQueue() {
        this->destroy();
    }

    bool start(int size) {
        this->size = size;
        this->init = 0;
        this->end = 0;
        this->total = 0;
        this->data = new DataType[this->size];
        return (this->startup_verification());
    }

    bool startup_verification() {
        if (this->data != NULL) {
            return true;
        } else {
            return false;
        }
    }

    void destroy() {
        this->size = 0;
        this->init = 0;
        this->end = 0;
        this->total = 0;
        if (this->startup_verification()) {
            delete[] (this->data);
            this->data = nullptr;
        }
    }

    bool is_empty() {
        if (this->total == this->size) {
            return true;
        } else {
            return false;
        }
    }

    bool push(DataType data) {
        if (!this->startup_verification() || this->is_empty())
            return false;

        this->data[this->end] = data;
        this->total++;
        this->end++;

        if (this->end >= this->size) {
            this->end = 0;
        }
        return true;
    }

    DataType pop() {
        DataType* aux = new DataType(NULL);

        if (this->is_empty()) {
            cerr << "> Err. Empty queue!\n";
            return (*aux);
        }

        *aux = this->data[this->init];
        this->total--;
        this->init++;

        if (this->init >= this->size) {
            this->init = 0;
        }

        return (*aux);
    }

    DataType peek() {
        DataType* aux = new DataType(NULL);

        if (this->is_empty()) {
            cerr << "> Err. Empty queue!\n";
            return (*aux);
        }

        *aux = this->data[this->init];
        return (*aux);
    }

    void show() {
        if (!this->is_empty()) {
            cout << "\n=> Stack (TAM: " << this->size
                << ", TOTAL: " << this->total
                << ") {\n";
            int index = this->init;
            for (int i = 0; i < this->total; i++) {
                cout << "\t" << this->data[index];

                if (i < this->total - 1)
                    cout << ", ";
                index++;
                cout << '\n';
                if (index >= this->size)
                    index = 0; // Circle
            }
            cout << "}\n";
        } else {
            cerr << "> Err. Empty queue!\n";
        }
    }
};

#endif // FILA_ESTATICA_HPP
