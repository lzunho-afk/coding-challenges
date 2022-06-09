/*
 * A Federação Gaúcha de Futebol contratou você para escrever um programa para fazer uma estatística
 * do resultado de vários GRENAIS. Escreva um programa para ler o número de gols marcados pelo Inter
 * e pelo Grêmio em um GRENAL. Logo após escrever a mensagem "Novo grenal (S-sim N-nao)" e solicitar
 * uma resposta. Se a resposta for ‘S’, o algoritmo deve ser executado novamente solicitando o número
 * de gols marcados pelos times em uma nova partida, caso contrário deve ser encerrado mostrando:
 *
 * - Quantos GRENAIS fizeram parte da estatística.
 * - O percentual de vitórias do Grêmio em relação ao total.
 * - O número de vitórias do Inter.
 * - O número de vitórias do Grêmio.
 * - O número de Empates.
 * - A média de gols por partida.
 * - Uma mensagem indicando qual o time que venceu o maior número de GRENAIS (ou
 * "Nao houve vencedor", caso termine empatado).
*/

#include <iostream>

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");
  std::cout.precision(2);

  int gols_gremio, gols_inter, vgremio, vinter, count, empates;
  char es = 'S';

  count = empates = vgremio = vinter = 0;
  while (es == 'S') {
    std::cout << "Grenal [" << count+1 << "]" << std::endl;

    std::cout << "Gols Grêmio: ";
    std::cin >> gols_gremio;

    std::cout << "Gols Internacional: ";
    std::cin >> gols_inter;
    
    if (gols_gremio == gols_inter)
      empates++;
    else if (gols_gremio > gols_inter)
      vgremio++;
    else
      vinter++;
    
    count++;
    std::cout << "Novo grenal (S-sim, N-não): ";
    std::cin >> es;
  }

  std::cout << count << " grenais fizeram parte da estatística!" << std::endl
	    << "~> O Grêmio tem um percentual de vitórias de " << (100*vgremio)/count << "%" << std::endl
	    << "~> O Inter ganhou " << vinter << " partidas" << std::endl
	    << "~> O Grêmio ganhou " << vgremio << " partidas" << std::endl
	    << "~> Ocorreram " << empates << " empates" << std::endl;

  if (vinter > vgremio)
    std::cout << "\n\t~> O time que mais venceu grenais foi o Internacional!" << std::endl;
  else if (vinter < vgremio)
    std::cout << "\n\t~> O time que mais venceu grenais foi o Grêmio!" << std::endl;
  else
    std::cout << "\n\t~> Não houve vencedor!" << std::endl;
  
  return 0;
}
