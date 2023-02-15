/*
 * Crie um programa que declare uma estrutura (registro) para o cadastro de clientes.
 * a. Dever�o ser armazenados, para cada cliente: CPF, nome completo e ano
 * de nascimento.
 * b. Ao in�cio do programa, o usu�rio dever� informar o n�mero de clientes que ser�o
 * armazenados
 * c. O programa devera alocar dinamicamente a quantidade necess�ria de mem�ria
 * para armazenar os registros dos clientes.
 * d. O programa dever� pedir ao usu�rio que entre com as informa��es clientes.
 * e. Ao final, mostrar os dados armazenados e liberar a mem�ria alocada.
*/

#include <iostream>

using namespace std;

typedef struct cliente {
    string cpf;
    string nome;
    short nasc;
} Cliente;

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Cliente *p_client;
    unsigned int clients_count;
    cout << "Informe o n�mero de clientes: ";
    cin >> clients_count;

    p_client = new Cliente[clients_count];
    cout << "## Preenchimento de Dados ##\n";
    for (int i = 0; i < clients_count; i++) {
        cout << "Cliente " << i + 1 << ":\n";
        cout << "\tCPF: ";
        cin >> (p_client + i)->cpf;
        cin.ignore();
        cout << "\tNome: ";
        getline(cin, (p_client + i)->nome);
        cout << "\tData de Nascimento: ";
        cin >> (p_client + i)->nasc;
    }

    cout << "\n## Dump das Informa��es ##\n";
    for (int i = 0; i < clients_count; i++) {
        cout << "Cliente " << i+1
            << " se chama " << (p_client + i)->nome
            << ", tem o CPF " << (p_client + i)->cpf
            << " e nasceu no ano de " << (p_client + i)->nasc << ".\n";
    }
    delete[] p_client;
    return 0;
}
