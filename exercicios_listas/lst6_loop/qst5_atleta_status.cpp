/*
 * Escreva um algoritmo que receba o tempo de um atleta em uma prova de atletismo, sabendo que
 * serão registrados o tempo de 5 voltas no circuito, ao final apresente os seguintes dados:
 * - Melhor tempo e em que volta ele ocorreu;
 * - Média de tempo entre todas as voltas;
 * - Pior tempo e em que volta ele ocorreu;
 * - Tempo total da prova;
*/

#include <iostream>

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "Portuguese");
  std::cout.precision(2);

  double tempo, med_tempo, tempo_bx, tempo_al, tempo_total;

  for(int i = 0; i < 5; i++) {
    std::cout << "Tempo na volta " << i+1 << ": ";
    std::cin >> tempo;

    if (i == 0 || tempo < tempo_bx)
      tempo_bx = tempo;

    if (tempo > tempo_al)
      tempo_al = tempo;

    tempo_total += tempo;
  }

  std::cout << "Melhor tempo\t~> " << std::fixed << tempo_bx << std::endl
	    << "Média de tempo\t~> " << std::fixed << (tempo_total)/5.00 << std::endl
	    << "Pior tempo\t~> " << std::fixed << tempo_al << std::endl
	    << "Tempo total\t~> " << std::fixed << tempo_total << std::endl;
  return 0;
}
