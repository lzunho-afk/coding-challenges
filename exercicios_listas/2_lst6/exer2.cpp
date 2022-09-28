/*
 * Faça um programa que realize o cadastro de contas bancárias com as seguinte
 * informações: número da conta, nome do cliente e saldo. O banco permite o
 * cadastramento de 10 contas e não poderá haver mais que uma conta com o mesmo
 * número. O sistema deverá apresentar um menu com as seguintes opções:
 *  1 – Cadastrar contas;
 *  2 – Visualizar dados da conta; (deve ser informado o número da conta)
 *  3 – Depositar; (deve ser informado o número da conta e o valor a ser
 *  depositado)
 *  4 – Sacar; (deve ser informado o número da conta e o valor a ser sacado,
 *  validar se o saque pode ser realizado ou não)
 *  5 – Pix; (deve ser informado o número da conta de origem, o número da conta
 *  de destino e o valor, existindo saldo na conta de origem o programa deve
 *  realizar a transferência, atualizando o saldo nas duas contas)
 *  6 – Sair;
 */

#include <iostream>
#include <limits>
#include <string>

#define CONTAS_BANCO 10

using namespace std;

const char* menu = "### Banco (Max: 10 contas) ###\n" \
                   "1 - Cadastrar contas\n"
                   "2 - Visualizar dados da conta\n"
                   "3 - Depositar\n"
                   "4 - Sacar\n"
                   "5 - Pix\n"
                   "6 - Sair\n"
                   ": ";

struct conta_banco {
    string nome;
    double saldo;
    unsigned int num;
};

void visualizar(struct conta_banco& conta_ptr) {
    cout << "> Conta número " << conta_ptr.num << " em nome de " << conta_ptr.nome << endl
        << "\tSaldo -> " << conta_ptr.saldo << endl;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    struct conta_banco contas[CONTAS_BANCO];
    string nome;
    unsigned int conta_num, conta_num2;
    long double val;
    short es;
    bool run = true;
    bool cad_ft = false;

    while (run) {
        cout << menu;
        cin >> es;

        switch(es) {
            case 1:
                for (int i = 0; i < CONTAS_BANCO; i++) {
                    cout << "> [" << i+1 << "] Informe o nome: ";
                    getline(cin, nome);
                    if (i == 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<int>::max(), '\n');
                    }
                    contas[i].nome = nome;
                    contas[i].num = i + 1;
                    contas[i].saldo = 0.00;
                }
                cad_ft = true;
                break;
            case 2:
                if (cad_ft) {
                    cout << "> Informe o número da conta: ";
                    cin >> conta_num;
                    if (conta_num >= 1 && conta_num <= 10) {
                        visualizar(contas[conta_num-1]);
                    } else {
                        cerr << "> Número de conta invalido!" << endl;
                    }
                } else {
                    cerr << "> Contas ainda não cadastradas!" << endl;
                }
                break;
            case 3:
                if (cad_ft) {
                    cout << "> Informe o número da conta: ";
                    cin >> conta_num;
                    cout << "> Informe o valor a ser depositado: ";
                    cin >> val;
                    if (conta_num >= 1 && conta_num <= 10) {
                        contas[conta_num - 1].saldo += val;
                    } else {
                        cerr << "> Número de conta invalido!" << endl;
                    }
                } else {
                    cerr << "> Contas ainda não cadastradas!" << endl;
                }
                break;
            case 4:
                if (cad_ft) {
                    cout << "> Informe o número da conta: ";
                    cin >> conta_num;
                    cout << "> Informe o valor a ser sacado: ";
                    cin >> val;
                    if (conta_num >= 1 && conta_num <= 10) {
                        if (contas[conta_num - 1].saldo >= val) {
                            contas[conta_num - 1].saldo -= val;
                        } else {
                            cerr << "> Saldo insuficiente!" << endl;
                        }
                    } else {
                        cerr << "> Número de conta invalido!" << endl;
                    }
                } else {
                    cerr << "> Contas ainda não cadastradas!" << endl;
                }
                break;
            case 5:
                if (cad_ft) {
                    cout << "> Informe o número da conta de origem: ";
                    cin >> conta_num;
                    cout << "> Informe o número da conta de destino: ";
                    cin >> conta_num2;
                    cout << "> Informe o valor do pix: ";
                    cin >> val;
                    if ((conta_num >= 1 && conta_num <= 10) && (conta_num2 >= 1 && conta_num2 <= 10)) {
                        if (contas[conta_num - 1].saldo >= val) {
                            contas[conta_num - 1].saldo -= val;
                            contas[conta_num2 - 1].saldo += val;
                        } else {
                            cerr << "> Saldo insuficiente!" << endl;
                        }
                    } else {
                        cerr << "> Número de conta invalido!" << endl;
                    }
                } else {
                    cerr << "> Contas ainda não cadastradas!" << endl;
                }
                break;
            case 6:
                run = false;
                break;
            default:
                cerr << "> Valor de entrada invalido!" << endl;
                break;
        }
    }
    return 0;
}
