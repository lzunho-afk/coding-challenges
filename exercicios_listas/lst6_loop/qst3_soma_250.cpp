/*
 * Escrever um programa que leia uma quantidade não determinada de vezes 
 * um número inteiro. Para cada número lido apresentar a soma dos números
 * lidos. Parar de informar quando a soma ultrapassar 250.
*/

#include <iostream>

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "Portuguese");

  int num, count;

  count = 0;
  while (count <= 250) {
    std::cout << "Número (Contador->" << count << "): ";
    std::cin >> num;

    count += num;
  }
  return 0;
}
