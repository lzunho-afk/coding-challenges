/*
 * Crie um programa para ler o tempo registrado por um atleta durante uma corrida
 * com N voltas, a leitura deve ocorrer em uma função e o registro do melhor tempo deve
 * ser atualizado através de um ponteiro. Encerrar o programa quando o número zero for
 * informado para o tempo, apresentar o melhor tempo.
*/
#include <iostream>

using namespace std;

void tempo_volta(int **ptr, int ct) {
  int n;
  cout << "> Tempo número " << ct << ": ";
  cin >> n;

  if (n > **ptr) {
    **ptr = n;
  }
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int n, *val, mvt=0;
  
  cout << "Informe quantas voltas: ";
  cin >> n;

  val = &mvt;
  for (int i = 0; i < n; i++) {
    tempo_volta(&val, i+1);
  }
  cout << "A maior volta é " << *val << endl;
  
  return 0;
}
