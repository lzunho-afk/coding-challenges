/*
 * Crie um programa que manipule uma matriz de inteiros m[7][7]. Utilizando
 * funções o programa deverá apresentar um menu para acionar as seguintes
 * funcionalidades:
 *  1 – Gerar valores para preencher a matriz, não sendo permitido números
 *  duplicados e devem ser menores que 100.
 *  2 – Mostrar a matriz na tela
 *  3 - Encontrar o maior elemento de cada linha e passá-lo para a posição
 *  da diagonal principal na linha e o elemento que estava na diagonal 
 *  principal para o local do número, exibir a matriza original e depois
 *  modificada.
 *  4 – Verificar se a Matriz é uma matriz simétrica
 *  5 – Mostrar os elementos acima e abaixo da diagonal principal
 */

#include <iostream>

#define TAM 7
#define RAND_DL 100

using namespace std;

const char* menu = "1 - Gerar valores\n"
                   "2 - Mostrar matriz\n"
                   "3 - Mover maior elemento de cada linha para a diagonal principal\n"
                   "4 - Verificar se é simétrica\n"
                   "5 - Mostrar os elementos acima e abaixo da diagonal principal\n"
                   "0 - Sair\n"
                   ": ";
int gen = false;

void generate_mtx(int mtx[TAM][TAM]);
void show_mtx(int mtx[TAM][TAM], string name);
void most2dg(int mtx[TAM][TAM]);
void ud_elements_dg(int mtx[TAM][TAM]);
bool issimetric(int mtx[TAM][TAM]);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int mtx[TAM][TAM];
    int es;

    while(true) {
        cout << menu;
        cin >> es;

        switch(es) {
            case 0:
                return 0;
            case 1:
                generate_mtx(mtx);
                break;
            case 2:
                show_mtx(mtx, "Matrix");
                break;
            case 3:
                most2dg(mtx);
                break;
            case 4:
                if (issimetric(mtx)) 
                    cout << "> A matriz É simétrica!" << endl;
                else
                    cout << "> A matriz NÃO É simétrica!" << endl;
                break;
            case 5:
                ud_elements_dg(mtx);
            default:
                cerr << "> Comando incorreto!" << endl;
                break;
        }
    };
    return 0;
}

void ud_elements_dg(int mtx[TAM][TAM]) {
    if (!gen) return;
    cout << "> Elementos acima da diagonal principal => {";
    for (int i = 0; i < TAM; i++) {
        for (int j = i + 1; j < TAM; j++) {
            cout << mtx[i][j] << ",";
        }
    }
    cout << "}" << endl << "> Elementos abaixo da diagonal principal => {";
    for (int i = 0; i < TAM; i++) {
        for (int j = i - 1; j >= 0; j--) {
            cout << mtx[i][j] << ",";
        }
    }
    cout << "}" << endl;
}

bool issimetric(int mtx[TAM][TAM]) {
    if (!gen) return false;
    int tmtx[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tmtx[j][i] = mtx[i][j];
        }
    }
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tmtx[i][j] != mtx[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void most2dg(int mtx[TAM][TAM]) {
    if (!gen) return;
    int aux, m_index, m_val, amtx[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            amtx[i][j] = mtx[i][j];
        }
    }

    for (int i = 0; i < TAM; i++) {
        m_index = 0;
        m_val = amtx[i][m_index];
        for (int j = 0; j < TAM; j++) {
            if (amtx[i][j] > m_val) {
                m_val = amtx[i][j];
                m_index = j;
            }
        }
        aux = amtx[i][i];
        amtx[i][i] = amtx[i][m_index];
        amtx[i][m_index] = aux;
    }
    show_mtx(mtx, "Original");
    show_mtx(amtx, "dg_modified");
}

void show_mtx(int mtx[TAM][TAM], string name) {
    if (!gen) return;
    cout << name << " {" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\t{";
        for (int j = 0; j < TAM; j++) {
            cout << mtx[i][j];
            if (j + 1 != TAM) {
                cout << ",";
            }
        }
        cout << "}";
        if (i + 1 != TAM) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "}" << endl;
}

// Geração com algoritmo Fisher-Yates
void generate_mtx(int mtx[TAM][TAM]) {
    srand(time(NULL));
    int ns[RAND_DL], aux, idx;
    for (int i = 0; i < RAND_DL; i++) {
        ns[i] = i;
    }

    for (int i = RAND_DL - 1; i > 0; i--) {
        idx = rand() % (i + 1);
        aux = ns[idx];
        ns[idx] = ns[i];
        ns[i] = aux;
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mtx[i][j] = ns[( i != 0 ? (TAM * i - 1) : 0) + j];
        }
    }
    gen = true;
}
