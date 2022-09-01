/*
 *  Escreva um programa que exiba um menu com as opções apresentadas abaixo 
 *  e quando acionada deve executar as ações descritas:
 *      0 – Sair - Encerra o programa
 *      1 – Ler um valor qualquer – Aciona uma função para ler um número 
 *      via entrada padrão
 *      2 – Verifica primo - Aciona uma função que recebe o número por 
 *      parâmetro e exibe a informação se o número é primo ou não, os
 *      números 0 e 1 por definição não são primos.
 *      3 – Soma algarismo - Aciona uma função que soma os algarismos que 
 *      compõem o número, por exemplo:
 *          se o número informado foi 528 a função deve retornar 15 pois
 *          5 + 2 + 8 = 15
*/

#include <iostream>
#include <cmath>

using namespace std;

const char *menu = "0 - Sair \n"
                    "1 - Ler um valor \n"
                    "2 - Verificar primo \n"
                    "3 - Soma Algarismo \n"
                    ": ";

void ler_num(int &n);
void verifica_primo(int n);
int soma_alg(int n);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int es, num;
    bool ready = false;
    bool run = true;

    while(run) {
        cout << menu;
        cin >> es;

        switch (es) {
            case 0:
                return 0;
            case 1:
                ler_num(num);
                ready = true;
                break;
            case 2:
                if (ready)
                    verifica_primo(num);
                else
                    cerr << "2> Nenhum valor foi informado!" << endl;
                break;
            case 3:
                if (ready) {
                    if (num > 0 && num <= 999) {
                        cout << "> A soma dos algarismos é " << soma_alg(num) << endl;
                    } else {
                        cerr << "2> Não é possível realizar essa opção com esse número! (Intervalo válido -> 1-999)" << endl;
                    }
                } else
                    cerr << "2> Nenhum valor foi informado!" << endl;
                break;
            default:
                cerr << "2> Opção inválida!" << endl;
                break;
        }
    }
    return 0;
}

void ler_num(int &n) {
    cout << "> Número: ";
    cin >> n;
}

void verifica_primo(int n) {
    int count = 0;

    if (n == 0 || n == 1) {
        cout << "> O número É PRIMO" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        cout << "> O número É PRIMO" << endl;
    } else {
        cout << "> O número NÃO É PRIMO" << endl;
    }
}

int soma_alg(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

