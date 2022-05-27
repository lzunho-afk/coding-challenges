/*
 * Escrever um programa que lê 12 valores reais para a variável “B”, um de 
 * cada vez. Mostrar a soma dos valores lidos menores que 50;
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "pt_BR");

  double b, aux;
  int count = 0;

  b = 0;
  while (count < 12) {
    std::cout << "Informe o " << count + 1 << "º número: ";
    std::cin >> aux;

    if (aux < 50) {
      b += aux;
    }
    count++;
  }
  std::cout << "A soma dos valores menores que 50 é " << b << "!\n";
  return 0;
}

