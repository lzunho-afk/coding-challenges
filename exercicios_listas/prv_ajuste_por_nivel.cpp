/*
 * O sindicato das escolas da rede particular de ensino orienta os diretores que
 * fazem o pagamento de seus professores por hora/aula que devem seguir a tabela
 * aprovada em assembleia do sindicado, conforme apresentada abaixo:
 *
 * Professor Nível 1 R$ 12.00 por hora/aula
 * Professor Nível 2 R$ 17.00 por hora/aula
 * Professor Nível 3 R$ 24.35 por hora/aula
 * Professor Nível 4 R$ 29.50 por hora/aula 
 *
 * Faça um algoritmo que receba o nível em que o professor se encontra na 
 * carreira (o sistema não deve aceitar informar nível diferente dos níveis 
 * apresentados acima), o número de horas que ele trabalha no mês e o valor do 
 * salário base que ele recebe. A seguir calcule se o valor está correto em 
 * relação a tabela do sindicato e apresente os seguintes resultados:
 *
 * Valor atual:
 * Valor pela tabela do sindicato:
 * Situação: (deve exibir o percentual que ele recebe a mais ou a menos em 
 * relação a tabela do sindicato), caso esteja igual deve exibir a mensagem 
 * dizendo “valor correto”;
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "pt_BR");
  std::cout.precision(2);

  int nvl, hrs_trab;
  double sal_base, sal_sind, hrs_val, situacao;

  std::cout << "Informe o nível: ";
  std::cin >> nvl;
  std::cout << "Informe o número de horas/mes trabalhadas: ";
  std::cin >> hrs_trab;
  std::cout << "Informe sua remuneração: R$ ";
  std::cin >> sal_base;

  switch (nvl) {
  case 1:
    hrs_val = 12.00;
    break;
  case 2:
    hrs_val = 17.00;
    break;
  case 3:
    hrs_val = 24.35;
    break;
  case 4:
    hrs_val = 29.50;
    break;
  default:
    std::cerr << "Nível do profissional não existe!!\n";
    return 1;
  }
  
  sal_sind = hrs_trab*hrs_val;
  situacao = (100.00*(sal_base-sal_sind))/sal_base;

  
  std::cout << "Valor atual: R$ " << std::fixed << sal_base << "\n"
	    << "Valor pela tabela do sindicato: R$ " << std::fixed << sal_sind << "\n"
	    << "Situação: " << std::fixed << situacao << " %\n";
  if (situacao == 0)
    std::cout << "\n\t~>Valor Correto!\n";
  return 0;
}
