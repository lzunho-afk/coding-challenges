/*
 * Escrever um algoritmo que leia um vetor A[10] de números inteiros. Mostrar o vetor 
 * lido. Ler um número inteiro e multiplicar todo o vetor pelo número lido. Mostrar o
 * vetor modificado.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");

  int a[10], x;

  for (int i = 0; i < 10; i++)
    {
      std::cout << "Informe o número " << i << ": ";
      std::cin >> a[i];
    }
  for (int i = 0; i < 10; i++) std::cout << "A[" << i << "] ~> " << a[i] << std::endl;

  std::cout << "\nPor favor, informe um número: ";
  std::cin >> x;

  for (int i = 0; i < 10; i++)
    {
      a[i] *= x;
      std::cout << "A[" << i << "] ~> " << a[i] << std::endl;
    }
  return 0;
}
