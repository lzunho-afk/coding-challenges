/*
 * Um posto está vendendo combustíveis com base na tabela de descontos abaixo.
 * Escreva um algoritmo que leia o número de litros vendidos, o tipo de 
 * combustível (codificado da seguinte forma: A-álcool G-Gasolina), calcule
 * e imprima o valor a ser pago pelo cliente, sabendo-se que o preço da gasolina
 * é de R$ 2.590 o litro e o álcool R$ 1.650.
 *
 * COMBUSTÍVEL; LITROS ABASTECIDOS; DESCONTO
 * Gasolina; Até 15 litros; 3.5%
 * Gasolina; Acima de 15 litros; 6%
 * Álcool; Até 20 litros; 3%
 * Álcool; Acima de 20 litros; 5%
*/

#include <iostream>

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");
  std::cout.precision(2);

  int litros;
  double preco;
  char tipo;

  std::cout << "Por favor, informe o número de litros e o tipo (A/G) do combustível: ";
  std::cin >> litros >> tipo;

  if (tipo == 'A') {
    preco = litros * 1.65;
    if (litros <= 20) 
      preco -= preco * (3.00/100.00);
    else
      preco -= preco * (5.00/100.00);
  } else {
    preco = litros * 2.59;
    if (litros <= 15)
      preco -= preco * (3.50/100.00);
    else
      preco -= preco * (6.00/100.00);
  }

  std::cout << "O valor a ser pago é de R$ " << std::fixed << preco << std::endl;
  return 0;
}
