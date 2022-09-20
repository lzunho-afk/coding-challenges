/*
 * Escreva um programa que implemente as seguintes funções:
 *  - Função para ler um número inteiro qualquer, maior que 10, considere
 *  que o dígito 0 “zero” não será informado na composição do valor lido.
 *  - Função para ler um número verificador inteiro entre 1 e 9 (inclusive
 *  1 e 9), valores fora deste intervalo não serão aceitos, validar a entrada.
 *  - Função RECURSIVA que conta quantas vezes o número verificador aparece
 *  no número inteiro lido e apresenta o resultado. Caso o número verificador
 *  não aparecer deve apresentar 0 como resposta.
 * OBS: Todas as funções devem ser acionadas na respectiva ordem no programa principal.
 */

#include <iostream>

using namespace std;

bool read_uinput(unsigned int &n1, short &n2) {
    cout << "Número inteiro qualquer (>10): ";
    cin >> n1;
    if (n1 < 10) return false;
    
    cout << "Informe o número verificador: ";
    cin >> n2;
    if (n2 < 1 || n2 > 9) return false;

    return true;
}

unsigned int ver_fq(unsigned int n, short fq_n) {
    if (n == 0) {
        return 0;
    } else if (n%10 == fq_n) {
        return 1 + ver_fq(n/10, fq_n);
    } else {
        return ver_fq(n/10, fq_n);
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    unsigned int input;
    short ver_n;
    bool run;

    run = true;
    while (run) {
        run = false;
        if (read_uinput(input, ver_n)) {
            cout << "> A frequencia do número " << ver_n << " é " << ver_fq(input, ver_n) << endl;
        } else {
            cerr << "> Entrada inválida!" << endl;
            run = true;
        }
    }
    return 0;
}
