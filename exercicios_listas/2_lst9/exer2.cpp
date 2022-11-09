/*
Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2. A função deverá
alocar um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e deverá apresentar:
- Os elementos do vetor x3.
- Os elementos do vetor x3 em ordem crescente.
- O maior e o menor elemento do vetor x3.
OBS: este exercício deve ser resolvido usando alocação dinâmica de memória, ponteiros e aritmética de
ponteiro
*/

#include <iostream>
#include <locale>

using namespace std;

int *uniao_conjunto(int **v1, int **v2) {

}

void get_vet(int **v) {
    int *c = new int(0);
    while (true) {
        cout << "Valor " << *c << " (escreva '0' para parar): ";
        cin >> **v;
        if (**v == 0) {
            delete **v;
            break;
        }
        (*v)++;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int *v1 = new int;
    int *v2 = new int;
    int *cj;

    cout << "> Informe o primeiro vetor: \n";
    get_vet(&v1);
    cout << "----------------------------------\n";
    cout << "> Informe o segundo vetor: \n";
    get_vet(&v2);
    cout << "----------------------------------\n";

    cj = uniao_conjunto(&v1, &v2);

    return 0;
}
