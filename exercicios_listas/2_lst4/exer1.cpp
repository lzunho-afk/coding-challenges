/*
 * Implemente um programa para manipular uma matriz de 5 x 5 de números
 * inteiros, deverá ser possível realizar as seguintes ações:
 *  - Gerar valores para a matriz, não sendo permitido números duplicados.
 *  - Mostrar os elementos da matriz
 *  - Mostrar os elementos da diagonal principal da matriz
 *  - Mostrar os elementos da diagonal secundária da matriz
 *  - Encontrar o maior elemento da matriz e exibir sua 
 *    posição (linha, coluna) onde se encontra
 * OBS: utilize funções e passagem de parâmetro para resolver cada parte deste exercício.
*/

#include <iostream>
#include <sstream>

#define TAM 5
#define RAND_DL 1000000

using namespace std;

const char* menu = "1 - Gerar valores\n"
                   "2 - Mostrar elementos\n"
                   "3 - Mostrar elementos da diagonal principal\n"
                   "4 - Mostrar elementos da diagonal secundária\n"
                   "5 - Maior elemento da matriz\n"
                   "0 - Sair\n"
                   ": ";
bool gen = false;

void gen_mtx(int mtx[TAM][TAM]);
void show_mtx(int mtx[TAM][TAM]);
void m_element(int mtx[TAM][TAM]);
void verify_gen(void);
string dg_prim(int mtx[TAM][TAM]);
string dg_sec(int mtx[TAM][TAM]);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int mtx[TAM][TAM];
    int es, maior[2];
    do {
        cout << menu;
        cin >> es;

        switch (es) {
            case 1:
                gen_mtx(mtx);
                break;
            case 2:
                show_mtx(mtx);
                break;
            case 3:
                cout << dg_prim(mtx);
                break;
            case 4:
                cout << dg_sec(mtx);
                break;
            case 5:
                m_element(mtx);
                break;
        }
    } while (es != 0);
    return 0;
}

void m_element(int mtx[TAM][TAM]) {
    if (!gen) return;
    int maior, lin, col;
    maior = lin = col = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (maior < mtx[i][j]) {
                maior = mtx[i][j];
                lin = i;
                col = j;
            }
        }
    }
    cout << "> O maior elemento da Matrix é " << maior << " que se encontra na linha " << lin << " e coluna " << col << "." << endl;
}

string dg_prim(int mtx[TAM][TAM]) {
    if (!gen) return NULL;
    string output("");
    output = "dg_prim {\n";
    for (int i = 0; i < TAM; i++) {
        output += '\t';
        output += to_string(mtx[i][i]);
        if (i != TAM - 1)
            output += ",";
        output += '\n';
    }
    output += "}\n";
    return output;
}

string dg_sec(int mtx[TAM][TAM]) {
    if (!gen) return NULL;
    string output("");
    output += "dg_sec {\n";
    for (int i = TAM - 1; i >= 0; i--) {
        output += '\t';
        output += to_string(mtx[(TAM - 1) - i][i]);
        if (i != 0) 
            output += ",";
        output += '\n';
    }
    output += "}\n";
    return output;
}

void show_mtx(int mtx[TAM][TAM]) {
    if (!gen) return;
    cout << "mtx[" << TAM << "][" << TAM << "] ~> {" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\t{" << endl;
        for (int j = 0; j < TAM; j++) {
            cout << "\t\t" << mtx[i][j];
            if (j + 1 != TAM) {
                cout << ",";
            } 
            cout << endl;
        }
        cout << "\t}";
        if (i + 1 != TAM) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "}" << endl;
}

void gen_mtx(int mtx[TAM][TAM]) {
    bool ds = false;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mtx[i][j] = rand() % RAND_DL;
            for (int h = 0; h < TAM; h++) {
                for (int l = 0; l < TAM; l++) {
                    if (mtx[i][j] == mtx[h][l] && (i != h && j != l)) {
                        ds = true;
                        break;
                    }
                }
                if (ds) break;
            }
            if (ds) j--;
        }
    }
    gen = true;
}

