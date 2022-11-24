/*
 * Faça um programa para ler um arquivo texto (o usuário deve fornecer o nome do arquivo)
 * e o programa deverá imprimir seu conteúdo na tela. E em seguida mostrar quantos
 * caracteres existem no arquivo.
*/

#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    ifstream textfile;
    string filename;
    char ch;
    unsigned int counter = 0;

    cout << "Informe o nome do arquivo: ";
    cin >> filename;

    // Abertura do arquivo
    textfile.open(filename, ios::in);
    if (textfile.is_open()) {
        while (textfile.get(ch)) {
            cout << ch;
            if (isalnum(ch) && ch != '\n') {
                counter++;
            }
        }
    } else {
        cerr << "> Não foi possível abrir o arquivo texto!!\n";
        return 1;
    }
    textfile.close();
    cout << "\n> OK (" << counter << " caracteres)" << "\n";
    return 0;
}
