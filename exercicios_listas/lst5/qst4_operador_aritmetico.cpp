/*
 * Dados três valores A, B e C, em que A e B são números inteiros e C é um caractere, 
 * pede-se para imprimir o resultado da operação de A por B se C for um símbolo de 
 * operador aritmético válido; caso contrário deve ser impressa uma mensagem de operador 
 * não definido. Tratar erro de divisão por zero.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "pt_BR");

  int n1, n2;
  char op;
  
  std::cout << "Escreva o operador seguido dos valores de entrada (ex.: \"+ a b\"): ";
  std::cin >> op >> n1 >> n2;

  if (op == '+')
    std::cout << "[Soma] ~> " << n1+n2 << std::endl;
  else if (op == '-')
    std::cout << "[Subtração] ~> " << n1-n2 << std::endl;
  else if (op == '*')
    std::cout << "[Multiplicação] ~> " << n1*n2 << std::endl;
  else if (op == '/')
    std::cout << "[Divisão] ~> " << n1/n2 << std::endl;
  else if (op == '%')
    std::cout << "[Resto] ~> " << n1%n2 << std::endl;
  else {
    std::cerr << "Operador não definido!" << std::endl;
    return 1;
  }
  return 0;
}
