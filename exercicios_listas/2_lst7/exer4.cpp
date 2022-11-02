
/*
 * Diz-se que um número inteiro N é um quadrado perfeito se existirem M 
 * números ímpares consecutivos a partir do valor 1 cuja soma é igual a N.
 * Neste caso N = M2. Exemplo: 16=1+3+5+7 (16 é igual à soma dos quatro 
 * primeiros ímpares a partir de 1) e 16=4^2. Logo 16 representa um quadrado
 * perfeito. Escreva um algoritmo que utilizando ponteiros e funções, 
 * verifique se um valor inteiro positivo fornecido pelo usuário é um 
 * quadrado perfeito ou não.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool ver_quadrado_perfeito(int *ptr) {
    int c = 1;
    while (c*c <= (*ptr)) {
	if (c*c == (*ptr))
	    return true;
	c++;
    }
    return false;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int n, *ptr;

    cout << "Informe o número: ";
    cin >> n;

    ptr = &n;
    if (ver_quadrado_perfeito(ptr))
	cout << "> É um quadrado perfeito!!\n";
    else
	cout << "> NÃO É um quadrado perfeito!!\n";
    return 0;
}
