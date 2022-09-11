/*
 * Crie um programa que manipule uma matriz 3 x 5 de números inteiros, o
 * sistema deverá utilizar funções para realizar as ações apresentadas 
 * abaixo:
 *  - Gerar valores para preencher toda a matriz, não sendo permitido 
 *  números maiores que 50 e somente números pares serão aceitos na matriz
 *  - Mostrar a matriz gerada e sua respectiva matriz transposta.
 *  - Calcular e mostrar o maior, o menor e a média dos elementos existentes
 *  na matriz.
 */

#include <iostream>

#define LIN 3
#define COL 5
#define RAND_DL 50

using namespace std;

const char* menu = "1 - Gerar valores da matriz\n"
                   "2 - Mostrar matriz e transposta\n"
                   "3 - Status matemático da matriz\n"
                   "0 - Sair\n"
                   ": ";
int gen = false;

void gen_mtx(int mtx[LIN][COL]);
void show_mtx(int mtx[LIN][COL], string name);
void stat_mtx(int mtx[LIN][COL]);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int es, mtx[LIN][COL];

    while (true) {
        cout << menu;
        cin >> es;

        switch(es) {
            case 0:
                return 0;
            case 1:
                gen_mtx(mtx);
                break;
            case 2:
                show_mtx(mtx, "Matriz");
                break;
            case 3:
                stat_mtx(mtx);
                break;
            default:
                cerr << "> Comando incorreto!" << endl;
                break;
        }
    }
    return 0;
}

void stat_mtx(int mtx[LIN][COL]) {
    if (!gen) return;
    cout.precision(2);

    int maior, menor, elem_sum = 0;
    maior = menor = mtx[0][0];

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (mtx[i][j] > maior) {
                maior = mtx[i][j];
            }
            if (mtx[i][j] < menor) {
                menor = mtx[i][j];
            }
            elem_sum += mtx[i][j];
        }
    }
    cout << "> O MAIOR elemento é " << maior << "." << endl
        << "> O MENOR elemento é " << menor << "." << endl
        << "> A MÉDIA dos elementos da matriz é " << fixed << (elem_sum * 1.00/LIN*COL * 1.00) << endl;
}

void show_mtx(int mtx[LIN][COL], string name) {
    if (!gen) return;
    cout << name << " {" << endl;
    for (int i = 0; i < LIN; i++) {
        cout << "\t{";
        for (int j = 0; j < COL; j++) {
            cout << mtx[i][j];
            if (j + 1 != COL) {
                cout << ",";
            }
        }
        cout << "}";
        if (i + 1 != LIN) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "}" << endl;
}

void gen_mtx(int mtx[LIN][COL]) {
    srand(time(NULL));
    int ns[RAND_DL], ns_idx, aux, idx;

    ns_idx = 0;
    for (int i = 0; i < RAND_DL; i++) {
        if (i == 0 || i % 2 == 0) {
            ns[ns_idx] = i;
            ns_idx++;
        }
    }

    for (int i = ns_idx - 1; i > 0; i--) {
        idx = rand() % (i + 1);
        aux = ns[idx];
        ns[idx] = ns[i];
        ns[i] = aux;
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            mtx[i][j] = ns[( i != 0 ? (COL * i - 1) : 0) + j];
        }
    }
    gen = true;
}

