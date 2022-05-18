/*
 * Escrever um algoritmo para uma empresa que decide dar um reajuste a seus
 * funcionários de acordo com os seguintes critérios:
 * a) 50% para aqueles que ganham menos do que três salários mínimos;
 * b) 20% para aqueles que ganham entre três até dez salários mínimos;
 * c) 15% para aqueles que ganham acima de dez até vinte salários mínimos;
 * d) 10% para os demais funcionários.
 * 
 * Leia o nome do funcionário, seu salário e o valor do salário mínimo. Calcule
 * o seu novo salário reajustado.
 * Escrever o nome do funcionário, o valor do reajuste e o seu novo salário.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "pt_BR");
  std::cout.precision(2);

  std::string nome_func;
  double sal, reaj, sal_min;

  std::cout << "Por favor, informe o nome e o salário do funcionário seguido do salário mínimo: ";
  std::cin >> nome_func >> sal >> sal_min;

  if (sal < sal_min*3)
    reaj = sal * (50.00/100.00);
  else if (sal < sal_min*10)
    reaj = sal * (20.00/100.00);
  else if (sal < sal_min*20)
    reaj = sal * (15.00/100.00);
  else
    reaj = sal * (10.00/100.00);
  
  sal += reaj;
  std::cout << "\nFuncionário: " << nome_func << "\n"
	    << "~> Reajuste de R$ " << std::fixed << reaj << "\n"
	    << "~> Salário final fica R$ " << std::fixed << sal << "\n";
  
  return 0;
}
