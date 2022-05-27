/*
 * Escrever um algoritmo que leia três valores inteiros e verifique se eles podem ser os 
 * lados de um triângulo. Se forem, informar qual o tipo de triângulo que eles formam: 
 * equilátero, isóscele ou escaleno.
 * Propriedade: o comprimento de cada lado de um triângulo é menor do que a soma dos 
 * comprimentos dos outros dois lados.
 * Triângulo Equilátero: aquele que tem os comprimentos dos três lados iguais;
 * Triângulo Isóscele: aquele que tem os comprimentos de dois lados iguais. Portanto, 
 * todo triângulo equilátero é também isóscele;
 * Triângulo Escaleno: aquele que tem os comprimentos de seus três lados diferentes.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "pt_BR");

  int tr1, tr2, tr3;

  std::cout << "Por favor, informe os lados do triângulo: ";
  std::cin >> tr1 >> tr2 >> tr3;

  if (tr1 < tr2 + tr3 && tr3 < tr1 + tr2 && tr2 < tr1 + tr3) {
    if (tr1 == tr2) {
      if (tr1 == tr3)
	std::cout << "~> Triângulo Equilátero";
      else
	std::cout << "~> Triângulo Isóscele";
    } else if (tr1 == tr3) {
      std::cout << "~> Triângulo Isóscele";
    } else
      std::cout << "~> Triângulo Escaleno";
  } else {
    std::cerr << "Os valores informados não formam um triângulo!" << std::endl;
    return 1;
  }
  std::cout << "\t{" << tr1 << ", " << tr2 << ", " << tr3 << "}" << std::endl;
  return 0;
}

