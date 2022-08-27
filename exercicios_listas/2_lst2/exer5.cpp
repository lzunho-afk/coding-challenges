/*
 * Crie um programa que ao ser iniciado deverá ser informado uma palavra 
 * chave (uma palavra qualquer informada pelo usuário), em seguida o 
 * programa deve solicitar que o usuário digite palavras, a cada palavra 
 * digitada deverá ser verificado se ele acertou a palavra chave, caso 
 * tenha acertado o programa deve apresentar uma mensagem e finalizar o 
 * teste, juntamente com o número de tentativas que foram necessárias. 
 * Caso o usuário não acertar e mesmo assim queira encerrar o programa
 * deverá digitar a palavra Fim.
 * OBS: o sistema não deve fazer distinção entre letras maiúsculas e 
 * minúsculas e não deverá ser utilizado acentuação e cedilha. A palavra 
 * Fim não pode ser utilizada como palavra chave.
 */

#include <iostream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    string keyword, input;
    bool run;
    int count;
    
    run = true;
    while (run) {
        run = false;
        cout << "Informe a palavra-chave: ";
        cin >> keyword;

        for (int i = 0; i < keyword.size(); i++) {
            if (!isalnum(keyword[i])) {
                cerr << "Palavra-chave invalida!" << endl;
                run = true;
                break;
            }
            keyword[i] = tolower(keyword[i]);
        }
        if (keyword == "fim") {
            return 0;
        }
    }

    count = 0;
    run = true;
    while (run) {
        run = true;
        cout << "Palavra-tentativa: ";
        cin >> input;
        count++;

        for (int i = 0; i < input.size(); i++) {
            if (!isalnum(input[i])) {
                cerr << "Palavra-tentativa invalida!" << endl;
                run = false;
                break;
            }
            input[i] = tolower(input[i]);
        }
        if (input == "fim") {
            run = false;
        } else if (input == keyword) {
            cout << "Sucesso!!! -- Tentativas: " << count << endl;
            run = false;
        }
    }
    return 0;
}
