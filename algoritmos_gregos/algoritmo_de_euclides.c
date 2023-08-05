/**
   @file algoritmo_de_euclides.c
   @brief Método simples e eficiente de encontrar o MDC de dois número desenvolvido por Arquimedes.

   O algoritmo (original) requere que os dois números de entrada "x" e "y" sejam inteiros e
   diferentes de zero. 
 */

#include <stdio.h>
#include <stdlib.h> // atoi()
#include <ctype.h> // isdigit()
#include <string.h> // strcmp()

#define PROGRAM_VERSION "ada-05082023 1.0"
#define COPYRIGHT_LINE "Copyright (c) [MIT License] 2022-2023 Lucas Zunho <lucaszunho17@gmail.com>"
#define USAGE_STRING "Usage: ./ada [OPTIONS] [MDC_NUM0] [MDC_NUM1]\n"
#define HELP_PANEL "Help Panel:\n"		\
    "\t--help/-h\t=> Painel de ajuda\n"		\
    "\t--usage\t\t=> String de uso\n"		\
    "\t--recursive\t=> Cálculo através de recursividade.\n"

/**
   @fn int verifica_entrada(const char *str)
   @brief Verifica se o valor desconhecido de entrada é um número inteiro.
   @param str Constante retirada do argv.
   @return Booleano especificando se o número é um número inteiro (1) ou não (0).
 */
int verifica_entrada(const char *str) {
    if (!str || !(*str))
	return 0;
    while (*str)
	if (!isdigit(*str++))
	    return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    int verboseflag = 0;
    int recursiveflag = 0;
    int mdc_nums[2];
    int c = 0;

    // Argumentos da linha de comando
    for (int i = 0; i < argc; i++) {
	if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
	    printf(HELP_PANEL);
	    return 0;
	} else if (strcmp(argv[i], "--usage") == 0) {
	    printf(USAGE_STRING);
	    return 0;
	} else if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
	    verboseflag = 1;
	} else if (strcmp(argv[i], "--recursive") == 0) {
	    recursiveflag = 1;
	} else if (strcmp(argv[i], argv[0]) != 0) {
	    if (verifica_entrada(argv[i])) {
		if (c < 2) {
		    mdc_nums[c] = atoi(argv[i]);
		    c++;
		    continue;
		}
	    }
	    fprintf(stderr, "Argumento \"%s\" é inválido, use --help para saber mais.\n", argv[i]);
	    return 1;
	}
    }
    
    // Cabeçalho do programa & Licença completa
    printf("%s -- MDC através do Algoritmo de euclides\n%s\n", PROGRAM_VERSION, COPYRIGHT_LINE);
    return 0;
}



