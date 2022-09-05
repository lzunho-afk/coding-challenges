/*
 * Escreva um programa que simule um caixa eletrônico, sabendo que o 
 * caixa dispõe das seguintes notas: 2, 5, 10, 20, 50 e 100. O caixa 
 * deve priorizar (sempre que possível) a entrega das notas de maior
 * valor, por exemplo:
 *  Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
 *  Saque 11,00: uma nota de 5, 3 notas de 2
 * Caso seja solicitado um valor inválido para saque deverá informar
 * uma mensagem com tal informação e solicitar a leitura de outro
 * valor.
 * Utilize funções para resolver este exercício.
 */

#include <iostream>

using namespace std;

const char* header = "## Caixa Eletrônico v0.1 ##\n"
                    "Notas de 2, 5, 10, 20, 50 e 100\n";

bool more = false;

void rec_notas(int &val, int dv);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    int aux, val_sq;
    int notas[6] = {100, 50, 20, 10, 5, 2};

    cout << header;
    while (true) {
        cout << "Informe o valor de saque: ";
        cin >> val_sq;
        if (val_sq == 3 || val_sq == 1 || val_sq <= 0) {
            cerr << "> Valor de saque inválido! Tente outro valor" << endl;
            continue;
        }
        break;
    }

    cout << "> Saque R$ " << double(val_sq) << ".00: ";
    for (int i = 0; i < 6; i++) {
        rec_notas(val_sq, notas[i]);
    }
    cout << endl;
    return 0;
}

void rec_notas(int &val, int dv) {
    int val_rt = val % dv;
    if (val_rt != val && val_rt != 3 && val_rt != 1) {
        if (more) {
            cout << ", ";
        }
        cout << val/dv << " notas de " << dv;
        val %= dv;
        more = true;
    } else if (val / dv >= 2) {
        if (more) {
            cout << ", ";
        }
        cout << val/dv - 1 << " notas de " << dv;
        val -= dv * (val/dv - 1);
        more = true;
    }
}
