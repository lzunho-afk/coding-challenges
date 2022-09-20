/*
 * Escreva um programa que receba um texto qualquer e utilizando uma 
 * função recursiva, apresente o texto de forma invertida.
 * Exemplo:
 *  Texto digitado: Minha Prova
 *  Resultado exibido: avorP ahniM
 * OBS: Validar o texto para não aceitar números e caracteres especiais,
 * exibindo mensagem de “Entrada inválida” e solicitando a leitura de um
 * novo texto.
 */

#include <iostream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    string text, aux;
    int aux_c = 0;
    bool run;

    run = true;
    while (run) {
        run = false;
        cout << "Informe o texto: ";
        getline(cin, text);

        for (int i = text.length() - 1; i >= 0; i--) {
            if (isalpha(text[i]) || int(text[i]) == 32) {
                aux[aux_c] = text[i];
                aux_c++;
            } else {
                cerr << "> Entrada inválida!" << endl;
                run = true;
                break;
            }
        }
    }

    for (int i = 0; i < aux_c; i++) {
        cout << aux[i];
    }
    cout << endl;
    return 0;
}
