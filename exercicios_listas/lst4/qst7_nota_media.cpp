/*
Escreva um algoritmo que receba 3 notas escolares de um aluno ap�s ler as notas o algoritmo dever�
fazer o c�lculo da m�dia de forma ponderada, sabendo que a nota 1 tem peso 2.5 a nota 2 tem peso 5.0
e a nota 3 tem peso 2.5, ap�s classifique o conceito deste aluno segundo a tabela abaixo:
D = media < 3
C = media entre 3 e 4.9
B = media entre 5 e 7.4
A = media maior que 7.4
Mostrar a m�dia do aluno e seu conceito.
*/

#include <iostream>

int main(void) {
  setlocale(LC_ALL, "pt_BR");
  std::cout.precision(1);

  double n1, n2, n3, med;
  char conc;

  std::cout << "Por favor, informe as tr�s notas: ";
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

  std::cout << "M�dia: " << std::fixed << med << "\nConceito: " << conc << "\n";
  return 0;
}
