/*
 * Crie um programa que apresente um menu com as seguintes opções:
 * 0 – Sair
 * 1 – Cadastrar
 * 2 – Mostrar
 * 3 – Consultar
 * Onde, a opção 1 permita que o usuário informe o nome completo de
 * uma pessoa e o sistema deverá incluir este nome em um arquivo
 * texto chamado “cadastro.txt”, colocando cada nome em uma linha
 * e mantendo os nomes já cadastrados.
 * Opção 2 deverá ler o arquivo texto e mostrar os nomes na tela.
 * Opção 3 deverá solicitar um nome qualquer e verificar se o nome
 * já existe no arquivo texto. Exibindo a respectiva informação na tela.
 */

#include <iostream>
#include <locale>
#include <fstream>

#define FILEPATH "cadastro.txt"

using namespace std;

const char* menu =  "0 - Sair\n"        \
                    "1 - Cadastrar\n"   \
                    "2 - Mostrar\n"     \
                    "3 - Consultar\n"   \
                    ": ";

void cadastrar(void) {
    ofstream textfile;
    string input;

    cout << "> Informe o nome: ";
    getline(cin, input);

    textfile.open(FILEPATH, ios::app);
    if (textfile.is_open()) {
        textfile << input << '\n';
    } else {
        cerr << "> Falha ao abrir arquivo!!\n";
        exit(1);
    }
    textfile.close();
}

void mostrar(void) {
    ifstream textfile(FILEPATH, ios::in);
    char ch;

    cout << "> Mostrando cadastros...\n";
    if (textfile.is_open()) {
        while (textfile.get(ch)) {
            cout << ch;
        }
    } else {
        cerr << "> Falha ao abrir arquivo!!\n";
        exit(1);
    }
    textfile.close();
}

void consultar(void) {
    ifstream textfile(FILEPATH, ios::in);
    string nome, fileinput;
    char chs[98];

    cout << "> Consultar por: ";
    getline(cin, nome);

    if (textfile.is_open()) {
        while (textfile.getline(chs, 98)) {
            fileinput = string(chs);
            if (fileinput == nome) {
                cout << "> " << nome << " está no cadastro!!\n";
                return;
            }
        }
        cerr << "> Nome não encontrado no cadastro!\n";
    } else {
        cerr << "> Falha ao abrir arquivo!!\n";
        exit(1);
    }
    textfile.close();
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int es;

    do {
        cout << menu;
        cin >> es;
        cin.ignore();
        switch (es) {
            case 0:
                break;
            case 1:
                cadastrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                consultar();
                break;
            default:
                cerr << "> Escolha inválida, tente novamente!\n";
                break;
        }
    } while (es != 0);
    return 0;
}
