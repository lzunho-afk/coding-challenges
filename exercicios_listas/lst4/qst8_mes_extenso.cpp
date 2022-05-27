/*
Escreva um programa que receba um número inteiro entre 1 e 12 referente ao número do mês, o
programa deverá exibir o mês por extenso, caso informado um número fora do intervalo, deverá
apresentar uma mensagem com esta informação.
*/

#include <iostream>

int main(void) {
  setlocale(LC_ALL, "pt_BR");

  short mes;
  std::string mes_ext;

  std::cout << "Por favor, informe o mês: ";
  std::cin >> mes;
  
  switch (mes) {
  case 1:
    mes_ext = "Janeiro";
    break;
  case 2:
    mes_ext = "Fevereiro";
    break;
  case 3:
    mes_ext = "Março";
    break;
  case 4:
    mes_ext = "Abril";
    break;
  case 5:
    mes_ext = "Maio";
    break;
  case 6:
    mes_ext = "Junho";
    break;
  case 7:
    mes_ext = "Julho";
    break;
  case 8:
    mes_ext = "Agosto";
    break;
  case 9:
    mes_ext = "Setembro";
    break;
  case 10:
    mes_ext = "Outubro";
    break;
  case 11:
    mes_ext = "Novembro";
    break;
  case 12:
    mes_ext = "Dezembro";
    break;
  default:
    std::cerr << "Mês fora do intervalo de 12 meses!\n";
    return 1;
  }
  std::cout << "O mês por extenso é " << mes_ext << "\n";
  return 0;
}
