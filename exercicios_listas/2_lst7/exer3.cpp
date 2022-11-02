/*
 * Crie um programa que manipule um vetor de 10 posições através de ponteiro.
 * O sistema deverá gerar os 10 valores randomicamente, sendo maior que 25 e
 * menor que 60, o sistema deverá disponibilizar as seguintes opções no menu:
 * 0 – Sair
 * 1 – Gerar valores
 * 2 – Mostrar soma dos valores
 * 3 – Mostrar maior e menor valor
 * 4 – Solicitar a leitura de um valor e verificar se o valor existe no vetor
 * indicando a sua posição.
 * OBS: as opções 2, 3 e 4 só poderão ser acionadas após ter sido executado a
 * ação 1.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const char* menu = "0 - Sair\n"						\
    "1 - Gerar valores\n"						\
    "2 - Mostrar soma dos valores\n"					\
    "3 - Mostrar maior e menor valor\n"					\
    "4 - Verificar existencia\n"					\
    ": ";

void gerar(int *vptr) {
    srand(time(NULL));
    cout << "## Geração ##\n";
    for (int i = 0; i < 10; i++) {
	*vptr = rand() % 33 + 26;
	cout << "> Valor " << i << " = " << (*vptr) << '\n';
	vptr++;
    }
}

void mostrar_soma(int *vptr) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
	soma += *vptr;
	vptr++;
    }
    cout << "> A soma dos valores é " << soma << '\n';
}

void mostrar_maior_e_menor(int *vptr) {
    int maior, menor;
    maior = menor = (*vptr);
    for (int i = 0; i < 10; i++) {
	if ((*vptr) > maior) {
	    maior = *vptr;
	}
	if ((*vptr) < menor) {
	    menor = *vptr;
	}
	vptr++;
    }
    cout << "> O MAIOR valor é " << maior << ", enquanto o MENOR é " << menor << '\n';
}

void verifica_numero(int *vptr) {
    int val;
    cout << "> Informe um número para verificação: ";
    cin >> val;

    for (int i = 0; i < 10; i++) {
	if (val == (*vptr)) {
	    cout << "> O valor está na posição " << i << '\n';
	    return;
	}
	vptr++;
    }
    cerr << "> Valor não encontrado!!\n";
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int vet[10], es, *ptr;
    bool run, ready;

    ptr = &vet[0];
    ready = false;
    run = true;
    while (run) {
	cout << menu;
	cin >> es;

	switch(es) {
	case 0:
	    run = false;
	    break;
	case 1:
	    gerar(ptr);
	    ready = true;
	    break;
	case 2:
	    if (ready)
		mostrar_soma(ptr);
	    else cerr << "> Números ainda não gerados!!\n";
	    break;
	case 3:
	    if (ready)
		mostrar_maior_e_menor(ptr);
	    else cerr << "> Números ainda não gerados!!\n";
	    break;
	case 4:
	    if (ready)
		verifica_numero(ptr);
	    else cerr << "> Números ainda não gerados!!\n";
	    break;
	default:
	    cerr << "> Alternativa inválida!!\n";
	    break;
	}
    }
    return 0;
}
