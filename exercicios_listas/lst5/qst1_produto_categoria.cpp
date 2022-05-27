/*
 * Escreva um programa que receba o preço de custo de um produto e o código da
 * sua categoria (conforme tabela apresentada), caso for informado uma categoria
 * diferente das apresentadas, deve apresentar mensagem de “Categoria inválida”
 *  e finalizar o programa, caso a categoria seja válida o programa deverá 
 * calcular o preço de venda, conforme margem de lucro da categoria.
 * 
 * Código da Categoria: {1,2,3,4}
 * Margem de lucro (%): {35%,28%,22%,15%}
*/

#include <iostream>

int main(void) {
  setlocale(LC_ALL, "pt_BR");
  std::cout.precision(2);

  int cod;
  double preco, margem;

  std::cout << "Por favor, informe o código e o valor do produto: ";
  std::cin >> cod >> preco;
  
  switch (cod) {
  case 1:
    margem = 35.00;
    break;
  case 2:
    margem = 28.00;
    break;
  case 3:
    margem = 22.00;
    break;
  case 4:
    margem = 15.00;
    break;
  default:
    std::cerr << "Código invalido!\n";
    return 1;
  }
  preco += preco*(margem/100.00);
  std::cout << "Código: " << cod << "\tPreço de Venda: R$ " << std::fixed << preco << "\n";
  return 0;
}
