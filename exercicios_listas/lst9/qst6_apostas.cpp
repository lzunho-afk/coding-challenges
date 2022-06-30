/*
 * Crie um algoritmo para simular um jogo de apostas onde o usuário deverá informar 6
 * números do tipo inteiro não aceitando valores repetidos, o sistema deverá gerar
 * dinamicamente 6 valores sorteados que também não podem ser repetidos e devem ser
 * entre 1 e 60 (inclusive), após o algoritmo deve apresentar os valores sorteados,
 * os valores apostados pelo usuário e quantos acertos ele teve, caso ele tenha 
 * acertado menos de 4 valores deve exibir a mensagem: “Você não ganhou nada”, 4
 * acertos “Você acertou a quadra”, 5 acertos “Você acertou a quina”, 6 acertos
 * “Parabéns você está milionário”.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int ubet[6], res[6], count;

  for (int i = 0; i < 6; i++)
    {
      std::cout << "Informe o número " << i+1 << ": ";
      std::cin >> ubet[i];
    }

  std::cout << "Valores sorteados: " << std::endl;
  for (int i = 0; i < 6; i++)
    {
      res[i] = rand() % 60 + 1;
      std::cout << "\t" << i+1 << "~>" << res[i] << std::endl;

      for (int j = 0; j < i; j++)
	{
	  if (res[i] == res[j]) i--;
	}
    }

  std::cout << "\nApostas: " << std::endl;
  count = 0;
  for (int i = 0; i < 6; i++)
    {
      std::cout << "\t" << i+1 << "~>" << ubet[i] << std::endl;
      for (int j = 0; j < 6; j++)
	{
	  if (ubet[i] == res[j])
	    count++;
	}
    }

  std::cout << std::endl;
  if (count < 4)
    {
      std::cout << "Você não ganhou nada" << std::endl;
    }
  else if (count == 4)
    {
      std::cout << "Você ganhou a quadra" << std::endl;
    }
  else if (count == 5)
    {
      std::cout << "Você ganhou a quina" << std::endl;
    }
  else
    {
      std::cout << "Parabéns você está milionário" << std::endl;
    }
  return 0;
}
