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
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define CONTAS_BANCO 10
#define NAME_SIZE 50

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
    char nome[NAME_SIZE];
    double saldo;
    unsigned int num;
};

void contas_pr(struct conta_banco* contas_ptr) {
    conta_banco* conta;
    for (int i = 0; i < CONTAS_BANCO; i++) {
        conta = contas_ptr + sizeof(struct conta_banco) * (i+1);
        conta->num = i;
        conta->saldo = 0.00;
    }
}

void cadastrar(struct conta_banco* conta) {
    char* nome;
    size_t nome_size = NAME_SIZE;
    size_t chs_rd;

    nome = (char*) malloc(sizeof(char) * NAME_SIZE);
    cout << "> Cadastro:" << endl
        << "\tNome: ";
    chs_rd = getline(&nome, &nome_size, stdin);
    strcpy(conta->nome, nome);

    cout << "> Cadastro realizado para \"" << conta->nome << "\" ~> Número da conta => " << conta->num << endl;
}

void mostrar_conta(struct conta_banco* conta) {
    cout.precision(2);
    cout << endl << "\t~> Conta em nome de " << conta->nome << endl
        << "\tSaldo => " << fixed << conta->saldo << endl
        << "\tNúmero da conta => " << conta->num << endl << endl;
}

void visualizar(struct conta_banco* contas_ptr) {
    conta_banco* conta;
    int conta_num;
    int ver_count = 0;
    
    cout << "> Informe o número da conta: ";
    cin >> conta_num;

    for (int i = 0; i < CONTAS_BANCO; i++) {
        conta = contas_ptr + sizeof(struct conta_banco) * (i+1);
        if (conta->num == conta_num) {
            mostrar_conta(conta);
            return;
        }
    }
    cerr << "> Conta não encontrada!" << endl;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    struct conta_banco contas[CONTAS_BANCO];
    unsigned int banco_count = 0;
    int es;
    bool run = true;

    contas_pr(&(contas[0]));
    while (run) {
        cout << menu;
        cin >> es;

        switch(es) {
            case 1:
                cadastrar(&(contas[banco_count]));
                banco_count++;
                break;
            case 2:
                visualizar(&(contas[0]));
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                pix();
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
