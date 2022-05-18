/*
 * Escreva um programa que receba um número inteiro N qualquer, de tal forma que
 * N > 0 e N < 9999, validar para aceitar número no intervalo definido.
 * Se o valor informado for válido, apresentar uma mensagem indicando se o 
 * número é uma dezena, uma centena ou um milhar.
*/

#include <iostream>

int main(void)
{
  int n, aux;
  short count = 0;

  std::cout << "Por favor, informe o número: ";
  std::cin >> n;

  if ((n < 0) || (n > 9999)) {
    std::cerr << "Número fora do intervalo [N > 0 e N < 9999]\n";
    return 1;
  }

  if (n >= 1000)
    std::cout << "O número " << n << " é um MILHAR!\n";
  else if (n >= 100)
    std::cout << "O número " << n << " é uma CENTENA!\n";
  else
    std::cout << "O número " << n << " é uma DEZENA!\n";
  return 0;
}
