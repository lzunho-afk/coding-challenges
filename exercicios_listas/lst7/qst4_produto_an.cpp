/*
 * Faça um algoritmo que leia o código do produto, a quantidade em estoque, 
 * o preço de custo e o tipo (S – serviço, P - produto). Com base na 
 * quantidade de produtos em estoque (Qt. Estoque) e preço de custo (Preço Custo), o
 * programa deve calcular e mostrar o valor do total de produtos em estoque 
 * (Valor Estoque), e também o preço de venda com base nas seguintes informações:
 * 
 * - Se o tipo for P de Produto, o preço de venda é calculado com 90% sobre o 
 * preço de custo.
 * - Se o tipo S de Serviço, o preço de venda é calculado com 65% sobre o 
 * preço de custo.
*/

#include <iostream>

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "Portuguese");
  std::cout.precision(2);
  
  int estoque, codigo;
  double valor_estoque, preco_custo, preco_venda;
  char tipo;

  std::cout << "Código: ";
  std::cin >> codigo;
  
  std::cout << "Quantidade em estoque: ";
  std::cin >> estoque;

  std::cout << "Preço de custo: R$ ";
  std::cin >> preco_custo;

  std::cout << "Tipo (S/P): ";
  std::cin >> tipo;

  if (tipo == 'P') 
    preco_venda = preco_custo * (90.00/100.00);
  else
    preco_venda = preco_custo * (65.00/100.00);
  
  valor_estoque = estoque * preco_custo;
  std::cout << "\nValor estoque\t~> " << std::fixed << valor_estoque << "\n";

  valor_estoque = estoque * preco_venda;
  std::cout << "Valor venda\t~> " << std::fixed << valor_estoque << "\n\n";
  
  return 0;
}
