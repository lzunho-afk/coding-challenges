/*
 * Crie um programa que apresente um menu com as opções listadas a seguir:
 * 0 – Sair
 * 1 – Gerar valores para a matriz (gera valores para preencher uma matriz
 * 8 x 8 de números inteiros)
 * 2 – Escrever valores no arquivo texto (escreve os valores constantes na
 * matriz em um arquivo texto chamado matriz.txt, separando os elementos de
 * cada linha com uma vírgula)
 * 3 – Ler valores do arquivo e mostrar na tela no formato da matriz.
 *
 * OBS: os valores gerados para a matriz devem ser menores que 100, não
 * será permitido executar as opções 2 e 3 do menu caso não tenha sido
 * executado a opção 1.
 */

#include <iostream>
#include <locale>
#include <fstream>
#include <iomanip>
#include <ctime>

#define FILEPATH "matriz.txt"
#define MTX_SIZE 8
#define RAND_DEL 100

using namespace std;

const char* menu =  "0 - Sair\n"                                \
                    "1 - Gerar valores para a matriz [8][8]\n"  \
                    "2 - Escrever valores no arquivo texto\n"   \
                    "3 - Ler valores do arquivo e mostrar\n"    \
                    ": ";

void gen_values(int mtx[MTX_SIZE][MTX_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < MTX_SIZE; i++) {
        for (int j = 0; j < MTX_SIZE; j++) {
            mtx[i][j] = rand() % RAND_DEL + 1;
        }
    }
}

void write_values(int mtx[MTX_SIZE][MTX_SIZE]) {
    ofstream textfile(FILEPATH, ios::out);
    if (textfile.is_open()) {
        for (int i = 0; i < MTX_SIZE; i++) {
            for (int j = 0; j < MTX_SIZE; j++) {
                textfile << mtx[i][j] << ',';
            }
            textfile << '\n';
        }
        textfile.close();
    } else {
        cerr << "Err.: Falha ao abrir o arquivo de texto!\n";
        exit(1);
    }
}

int casas(int n) {
    int c = 1;
    while (n % 10 > 9) {
        n /= 10;
        c++;
    }
    return c;
}

void read_file_values(void) {
    ifstream textfile(FILEPATH, ios::in);
    char chs[33];
    int c = 0;

    if (textfile.is_open()) {
        cout << "Matriz (Arquivo)\n";
        while (textfile.getline(chs, 33, ',')) {
            cout << left << setw(5) << chs;
            if (c + 1 == MTX_SIZE) {
                c = 0;
                cout << '\n';
            } else {
                c++;
            }
        }
    } else {
        cerr << "Err.: Falha ao abrir o arquivo de texto!\n";
        exit(1);
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int mtx[MTX_SIZE][MTX_SIZE];
    int es;
    bool file_use = false;

    do {
        cout << menu;
        cin >> es;
        switch(es) {
            case 0:
                break;
            case 1:
                gen_values(mtx);
                file_use = true;
                break;
            case 2:
                if (file_use) write_values(mtx);
                else cerr << "> É necessário utilizar a opção 1 primeiro!!\n";
                break;
            case 3:
                if (file_use) read_file_values();
                else cerr << "> É necessário utilizar a opção 1 primeiro!!\n";
                break;
            default:
                cerr << "> Invalid option!!\n";
                break;
        }
    } while (es != 0);
    return 0;
}
