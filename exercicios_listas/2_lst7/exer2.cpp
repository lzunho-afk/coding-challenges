/*
 * Crie um programa para controlar o estoque de uma empresa, sabendo que serão no
 * máximo 50 produtos (mas o sistema deve funcionar para qualquer quantidade inferior
 * ao máximo permitido), o sistema deverá manipular o código do produto, nome, unidade
 * (kg, dz, m, un, cx, tn, etc...), valor de venda e quantidade em estoque. O sistema
 * deverá utilizar ponteiro para manipular a struct e apresentar um menu com as seguintes
 * opções:
 * 0 – Sair
 * 1 – Cadastrar produto
 * 2 – Listar produtos cadastrados
 * 3 – Consultar produto pelo código
 * 4 – Vender produto (fornece o código e a quantidade de venda, o sistema verifica se
 * existe estoque suficiente e executa a venda atualizando a quantidade em estoque).
*/

#include <iostream>

using namespace std;

struct produto {
  string nome;
  string unidade;
  unsigned int codigo;
  unsigned int valor;
  unsigned int estoque;
};

struct produtos_lista {
  struct produto produto;
  struct produtos_lista *prx_produto;
};

typedef struct produtos_lista *Produtos;

const char* menu =				\
  "0 - Sair\n"					\
  "1 - Cadastrar produto\n"			\
  "2 - Listar produtos cadastrados\n"		\
  "3 - Consultar produto pelo código\n"		\
  "4 - Vender produto\n"			\
  ": ";

void cadastrar(Produtos *produtos) {
  struct produto aux;
  cout << "### Cadastro de Produto ###" << endl;
  cout << "> Nome: ";
  cin >> aux.nome;
  
  cout << "> Código: ";
  cin >> aux.codigo;
  
  cout << "> Valor: ";
  cin >> aux.valor;

  cout << "> Unidade: ";
  cin >> aux.unidade;

  cout << "> Estoque disponivel: ";
  cin >> aux.estoque;

  (*produtos)->produto = aux;
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  Produtos produtos;
  bool run;
  int es;

  run = true;
  while (run) {
    cout << menu << endl;
    cin >> es;

    switch (es) {
    case 0:
      run = false;
      break;
    case 1:
      cadastrar(&produtos);
    }
  }
  return 0;
}
