/*
 * Escrever um programa que leia um número inteiro, positivo menor ou igual
 * a 10. Montar e mostrar a tabuada deste número, como o exemplo abaixo.
 * Informe um número: _
 * Tabuada do 8
 * 1 x 8= 8
 * 2 x 8 = 16
 * .
 * .
 * 10 x 8 = 80
*/

#include <iostream>

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "Portuguese");

  int num;
  
  std::cout << "Informe um número: ";
  std::cin >> num;

  std::cout << "Tabuada do " << num << std::endl;
  for(int i = 1; i <= 10; i++) {
    std::cout << num << " x " << i << " = " << num*i << std::endl;
  }
  return 0;
}
