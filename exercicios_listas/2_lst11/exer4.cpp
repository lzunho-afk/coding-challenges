/*
 * Crie um programa que leia um arquivo texto chamado “números.txt”, o
 * qual contém uma série de números separados por ponto e vírgula, o
 * sistema deverá ler os números necessários para preencher uma matriz
 * 5 x 5 de números inteiros.
 * Após ler os dados o sistema deverá exibir um menu com as seguintes ações:
 * 1 – Mostrar elementos da diagonal principal
 * 2 – Mostrar os elementos da diagonal secundária
 * 3 – Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal
 * principal.
 */

#include <iostream>
#include <locale>
#include <fstream>

#define FILEPATH "numeros.txt"
#define MTX_SIZE 5

using namespace std;

const char* menu =  "0 - Sair\n"                                                                         \
                    "1 - Mostrar elementos da diagonal principal\n"                                      \
                    "2 - Mostrar elementos da diagonal secundária\n"                                     \
                    "3 - Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal\n" \
                    ": ";

void dig_principal(int mtx[MTX_SIZE][MTX_SIZE]) {
    cout << "-> Diagonal Principal (MTX) {\n";
    for (int i = 0; i < MTX_SIZE; i++) {
        cout << '\t' << mtx[i][i] << '\n';
    }
    cout << "}\n";
}

void dig_secundaria(int mtx[MTX_SIZE][MTX_SIZE]) {
    cout << "-> Diagonal Secundária (MTX) {\n";
    for (int i = 0; i < MTX_SIZE; i++) {
        cout << '\t' << mtx[i][MTX_SIZE - (i + 1)] << '\n';
    }
    cout << "}\n";
}

void mostrar_stats(int mtx[MTX_SIZE][MTX_SIZE]) {
    // Mostrando a Matriz
    cout << "-> Matriz:\n";
    for (int i = 0; i < MTX_SIZE; i++) {
        for (int j = 0; j < MTX_SIZE; j++) {
            cout << '\t' << mtx[i][j] << ", ";
        }
        cout << '\n';
    }

    // Elementos acima da diagonal principal
    cout << "-> Elemento ACIMA da diagonal principal => (";
    for (int i = 0; i < MTX_SIZE; i++) {
        for (int j = 0; j < MTX_SIZE; j++) {
            if (i < j) {
                cout << mtx[i][j] << ',';
            }
        }
    }
    cout << ")\n";

    // Elementos abaixo da diagonal principal
    cout << "-> Elemento ABAIXO da diagonal principal => (";
    for (int i = 0; i < MTX_SIZE; i++) {
        for (int j = 0; j < MTX_SIZE; j++) {
            if (i > j) {
                cout << mtx[i][j] << ',';
            }
        }
    }
    cout << ")\n";
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    ifstream textfile;
    int mtx[MTX_SIZE][MTX_SIZE];
    int es;
    char chs[12];

    // Leitura da matrix (5x5)
    textfile.open(FILEPATH, ios::in);
    if (textfile.is_open()) {
        for (int i = 0; i < MTX_SIZE; i++) {
            for (int j = 0; j < MTX_SIZE; j++) {
                textfile.getline(chs, 12, ';');
                mtx[i][j] = atoi(chs);
            }
        }
        textfile.close();
    } else {
        cerr << "> Falha ao abrir arquivo!!\n";
         return 1;
    }

    // Main Loop
    do {
        cout << menu;
        cin >> es;
        cin.ignore();
        switch (es) {
            case 0:
                break;
            case 1:
                dig_principal(mtx);
                break;
            case 2:
                dig_secundaria(mtx);
                break;
            case 3:
                mostrar_stats(mtx);
                break;
            default:
                cerr << "> Escolha inválida, tente novamente!\n";
                break;
        }
    } while (es != 0);
    return 0;
}
