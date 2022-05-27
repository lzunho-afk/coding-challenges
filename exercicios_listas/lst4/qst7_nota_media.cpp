/*
Escreva um algoritmo que receba 3 notas escolares de um aluno após ler as notas o algoritmo deverá
fazer o cálculo da média de forma ponderada, sabendo que a nota 1 tem peso 2.5 a nota 2 tem peso 5.0
e a nota 3 tem peso 2.5, após classifique o conceito deste aluno segundo a tabela abaixo:
D = media < 3
C = media entre 3 e 4.9
B = media entre 5 e 7.4
A = media maior que 7.4
Mostrar a média do aluno e seu conceito.
*/

#include <iostream>

int main(void) {
  setlocale(LC_ALL, "pt_BR");
  std::cout.precision(1);

  double n1, n2, n3, med;
  char conc;

  std::cout << "Por favor, informe as três notas: ";
  std::cin >> n1 >> n2 >> n3;

  med = (n1*2.5 + n2*5.0 + n3*2.5) / 10;
  if (med < 3)
    conc = 'D';
  else if (med <= 4.9)
    conc = 'C';
  else if (med <= 7.4)
    conc = 'B';
  else 
    conc = 'A';

  std::cout << "Média: " << std::fixed << med << "\nConceito: " << conc << "\n";
  return 0;
}
