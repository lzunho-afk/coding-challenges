/**
   @file raiz_quadrada_heron.c
   @brief Algoritmo com os passos descritos por Heron de Alexandria para cálcular a raiz quadrada.

   O algoritmo se baseia em cálculos sucessivos para se aproximar cada vez mais do valor exato.
   Primeiramente, chutamos um valor baixo "n" levando em consideração a raiz posta de "x" (nesse
   caso o valor inicial sempre será n=1); então, realizamos o cálculo de seu quadrado "n*n", já
   verificando se o valor coincide com o de "x"; após, fazemos a média de "n" com a divisão de "x"
   por "n", ou seja, "(n+x/n)/2"; com isso, consideramos "n" igual a essa média, repetindo o ciclo.
 */

#include <stdio.h>
#include <string.h> // strcmp

#define PROGRAM_VERSION "rqh-04082023 1.0"
#define COPYRIGHT_LINE "Copyright (c) [MIT License] 2022-2023 Lucas Zunho <lucaszunho17@gmail.com>"

int main(int argc, char **argv) {
    int verbose_opt = 0;
    double n = 1;
    double x;

    // Verificando os argumentos de linha de comando
    for (int i = 0; i < argc; i++) {
	if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
	    verbose_opt = 1;
	}
    }
    
    // Cabeçalho do programa & Licença completa
    printf("%s -- Raiz quadrada aos passos de Heron de Alexandria\n%s\n", PROGRAM_VERSION, COPYRIGHT_LINE);

    // uinput
    printf("Raíz quadrada a ser calculada: ");
    scanf("%lf", &x);

    // Cálculo
    n = (n+x/n)/2;
    while (n * n - x > 0.000001) {
	if (verbose_opt)
	    printf("[VERBOSE] %lf * %lf falhou! Tentando a próxima média...\n", n, n);
	n = (n+x/n)/2;
    }
    printf("~> O valor da raiz é %lf.\n", n);
    return 0;
}
