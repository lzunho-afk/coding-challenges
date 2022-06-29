/*
 * Escrever um algoritmo que gere dinamicamente valores inteiros para um vetor de 8 
 * posições, sendo esses valores entre 20 e 80. Encontrar o maior valor do vetor e
 * sua posição; mostrar ao final o maior valor e sua posição.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  int vet[8], maior, index;
  for (int i = 0; i < 8; i++) vet[i] = rand() % 60 + 20;

  maior = vet[0];
  for (int i = 0; i < 8; i++)
    {
      if (vet[i] >= maior)
	{
	  maior = vet[i];
	  index = i;
	}
    }
  std::cout << "O maior valor é " << maior << " que se encontra na posição " << index << std::endl;
  return 0;
}
