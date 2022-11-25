/*
 * Escreva um programa que leia um arquivo texto contendo vários números float,
 * separados por ponto e vírgula, o programa deverá mostrar a soma, média,
 * maior e menor valor existente no arquivo.
*/

#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);

    ifstream textfile;
    string filename, input;
    char chs[33];
    int counter = 0;
    double soma, maior, menor, aux;

    cout << "Informe o nome do arquivo: ";
    cin >> filename;

    textfile.open(filename, ios::in);
    if (textfile.is_open()) {
        while (textfile.getline(chs, 33, ';')) {
            aux = atof(chs);
            cout << "> Analisando o float " << fixed << aux << "...\n";

            if (counter == 0) {
                soma = maior = menor = aux;
            } else {
                soma += aux;
                if (maior < aux) {
                    maior = aux;
                }
                if (menor > aux) {
                    menor = aux;
                }
            }
            counter++;
        }
    } else {
        cerr << "> Erro na abertura do arquivo!\n";
        return 1;
    }

    cout << "> RESULTADO:\n"
        << "\t~> A soma dos elementos é " << fixed << soma << "\n"
        << "\t~> A média dos elementos é " << soma/counter << "\n"
        << "\t~> O maior elemento é " << maior << "\n"
        << "\t~> O menor elemento é " << menor << "\n";
    textfile.close();
    return 0;
}
