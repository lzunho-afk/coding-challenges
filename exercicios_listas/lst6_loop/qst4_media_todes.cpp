/*
 * Escreva um algoritmo que leia a quantidade de alunos de uma turma, após
 * solicite a média final de cada aluno da turma e apresente os seguintes
 * dados:
 * - Média da turma com uma casa decimal;
 * - Maior média entre os alunos;
 * - Menor média entre os alunos;
 * - Percentual de alunos aprovados (média >= 6);
 * - Percentual de alunos reprovados (média < 6);
*/

#include <iostream>

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "Portuguese");
  std::cout.precision(1);

  int alunos_count, alunos_appr, alunos_reppr;
  double aluno_med, med_aux, med_bx, med_al;

  std::cout << "Por favor, informe a quantidade de alunos: ";
  std::cin >> alunos_count;

  med_aux = med_bx = med_al = alunos_appr = alunos_reppr = 0;
  for (int i = 0; i < alunos_count; i++) {
    std::cout << "Média aluno " << i+1 << ": ";
    std::cin >> aluno_med;

    if (aluno_med >= 6)
      alunos_appr += 1;
    else
      alunos_reppr += 1;

    if (i == 0 || aluno_med < med_bx)
      med_bx = aluno_med;
    
    if (aluno_med > med_al)
      med_al = aluno_med;
    
    med_aux += aluno_med;
  }

  std::cout << "\nMédia da turma\t\t~> " << std::fixed << med_aux / alunos_count << "\n"
	    << "Maior média\t\t~> " << med_al << "\n"
	    << "Menor média\t\t~> " << med_bx << "\n"
	    << "Percentual Appr.\t~> " << ((100.00*alunos_appr)/alunos_count) << "\n"
	    << "Percentual Reppr.\t~> " << ((100.00*alunos_reppr)/alunos_count) << "\n\n";
  return 0;
}
