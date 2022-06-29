/*
 * Escrever um algoritmo que gere dinamicamente valores para dois vetores de 10 posições,
 * A e B. Mostrar os vetores gerados. Gerar um novo vetor Y, que será formado pela soma 
 * dos elementos das posições iguais nos vetores A e B. Mostrar o vetor Y.
 * Exemplo
 * A[0] <- 5
 * B[0] <- 4
 * Y[0] <- 9 (soma de 5 + 4)
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  int a[10], b[10], y[10];
 
  for (int i = 0; i < 10; i++)
    {
      a[i] = rand() % 1000000;
      std::cout << "A[" << i << "] ~> " << a[i] << std::endl;
    }
  std::cout << std::endl;
  for (int i = 0; i < 10; i++)
    {
      b[i] = rand() % 1000000;
      std::cout << "B[" << i << "] ~> " << b[i] << std::endl;
    }
  std::cout << std::endl;
  for (int i = 0; i < 10; i++)
    {
      y[i] = a[i] + b[i];
      std::cout << "Y[" << i << "] ~> " << y[i] << std::endl;
    }
  return 0;
}
