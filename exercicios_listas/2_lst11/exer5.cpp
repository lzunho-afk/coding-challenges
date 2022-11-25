/*
 * Crie um programa que manipule um arquivo texto contendo em cada linha
 * um número inteiro qualquer, o programa deverá ler todos os números e
 * apresentar os seguintes dados:
 * - Maior valor existente no arquivo
 * - Menor valor existente no arquivo
 * - Média aritmética dos valores no arquivo
 * - Quantidade de números pares e ímpares existentes no arquivo
 */

#include <iostream>
#include <locale>
#include <fstream>

#define FILEPATH "numeros2.txt"

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);

    ifstream textfile;
    long long int soma = 0;
    int maior, menor, par_count, imp_count, num, c;
    char chs[33];

    textfile.open(FILEPATH, ios::in);
    par_count = imp_count = 0;
    if (textfile.is_open()) {
        textfile.getline(chs, 33);
        num = atoi(chs);
        maior = menor = num;
        soma += num;

        if (num % 2 == 0) {
            par_count++;
        } else {
            imp_count++;
        }

        c = 1;
        while (textfile.getline(chs, 33)) {
            num = atoi(chs);
            soma += num;

            if (maior < num) {
                maior = num;
            }
            if (menor > num) {
                menor = num;
            }

            if (num % 2 == 0) {
                par_count++;
            } else {
                imp_count++;
            }
            c++;
        }

        textfile.close();
        cout << "Resultados:\n"
            << "\tMaior Valor: " << maior << '\n'
            << "\tMenor Valor: " << menor << '\n'
            << "\tMédia Aritmética: " << fixed << soma * 1.00/c << '\n'
            << "\tQuant. Números Pares: " << par_count << '\n'
            << "\tQuant. Números Ímpares: " << imp_count << '\n';
    } else {
        cerr << "Err.: Falha ao abrir o arquivo de texto!\n";
        return 1;
    }
    return 0;
}
