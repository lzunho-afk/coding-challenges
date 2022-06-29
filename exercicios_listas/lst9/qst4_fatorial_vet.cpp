/*
 * Escreva um algoritmo que leia valores para preencher um vetor de 5 posições de números
 * inteiros, após o sistema deverá gerar um segundo vetor, também de 5 posições, sendo
 * formado pelo fatorial do elemento no primeiro vetor.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");

  unsigned long long int vet[5], fat[5];
  for (int i = 0; i < 5; i++)
    {
      std::cout << "Informe o número " << i << ": ";
      std::cin >> vet[i];
      fat[i] = 1;
    }
  std::cout << std::endl;
  for (int i = 0; i < 5; i++)
    {
      for (int j = 1; j <= vet[i]; j++)
	{
	  fat[i] *= j;
	}
      std::cout << "Fatorial[" << i << "] ~> " << fat[i] << std::endl;
    }
  return 0;
}
