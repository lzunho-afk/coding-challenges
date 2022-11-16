/*
Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2. A função deverá
alocar um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e deverá apresentar:
- Os elementos do vetor x3.
- Os elementos do vetor x3 em ordem crescente.
- O maior e o menor elemento do vetor x3.
OBS: este exercício deve ser resolvido usando alocação dinâmica de memória, ponteiros e aritmética de
ponteiro
*/

#include <iostream>
#include <locale>
#include <cstdio>
#include <cstdlib>

using namespace std;

int *uniao_conjunto(int **v1, int *sz1, int **v2, int *sz2, int **cj_res) {
    int *cj = new int[(*sz1) * (*sz2)];
    (*cj_res) = new int[(*sz1) * (*sz2)];
    int *cj_res_counter = new int(0);

    for (int *i = new int(0); *i < *sz1; (*i)++)
        *(cj + *i) = *(*v1 + *i);

    for (int *i = new int(0); *i < *sz2; (*i)++)
        *(cj + (*i + *sz1)) = *(*v2 + *i);

    for (int *i = new int(0); *i < (*sz1) + (*sz2); (*i)++) {
        for (int *j = new int(0); *j < (*sz1) + (*sz2); (*j)++) {
            if (*(cj + *i) == *(cj + *j) && *i != *j) {
                for (int *h = new int(0); *h <= *cj_res_counter; (*h)++) {
                    if (*(cj + *i) == *(*cj_res + *h)) {
                        break;
                    }
                    if ((*h) + 1 > (*cj_res_counter)) {
                        *(*cj_res + *cj_res_counter) = *(cj + *i);
                        (*cj_res_counter)++;
                        break;
                    }
                }
                break;
            }
            if ((*j) + 1 == (*sz1) + (*sz2)) {
                *(*cj_res + *cj_res_counter) = *(cj + *i);
                (*cj_res_counter)++;
            }
        }
    }
    return cj_res_counter;
}

void get_vet(int *v, int *tam) {
    int *buff = new int;
    for (int *i = new int(0); *i < *tam; (*i)++) {
        cin >> *buff;
        *v = *buff;
        v++;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int *v1, *v2, *cj, *sz1, *sz2, *cj_res, *cj_res_counter;
    int *maior, *menor, *aux;

    cout << "> PRIMEIRO VETOR \n" << "Tamanho do vetor: ";
    sz1 = new int;
    cin >> *sz1;

    v1 = new int[(*sz1)];
    get_vet(v1, sz1);

    cout << "----------------------------------\n";

    cout << "> SEGUNDO VETOR \n" << "Tamanho do vetor: ";
    sz2 = new int;
    cin >> *sz2;

    v2 = new int[(*sz2)];
    get_vet(v2, sz2);

    cout << "----------------------------------\n";

    cj_res_counter = uniao_conjunto(&v1, sz1, &v2, sz2, &cj_res);

    cout << "Conjunto X3 (União): {\n";
    maior = new int;
    menor = new int;
    (*maior) = (*menor) = *cj_res;
    for (int *i = new int(0); *i < *cj_res_counter; (*i)++) {
        if (*(cj_res + *i) > (*maior)) {
            (*maior) = *(cj_res + *i);
        }
        if (*(cj_res + *i) < (*menor)) {
            (*menor) = *(cj_res + *i);
        }
        cout << "\t" << *(cj_res + *i) << ", \n";
    }
    cout << "}\nConjunto X3 (União) - Ordem Crescente: {\n";
    aux = new int;
    for (int *i = new int(0); *i < *cj_res_counter; (*i)++) {
        for (int *j = new int(0); *j < *cj_res_counter; (*j)++) {
            if (*(cj_res + *i) < *(cj_res + *j)) {
                (*aux) = *(cj_res + *i);
                *(cj_res + *i) = *(cj_res + *j);
                *(cj_res + *j) = (*aux);
            }
        }
    }
    for (int *i = new int(0); *i < *cj_res_counter; (*i)++)
        cout << "\t" << *(cj_res + *i) << ", \n";
    cout << "}\n";

    return 0;
}
