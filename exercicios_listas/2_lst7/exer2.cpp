/*
 * Crie um programa para controlar o estoque de uma empresa, sabendo que 
 * serão no máximo 50 produtos (mas o sistema deve funcionar para qualquer
 * quantidade inferior ao máximo permitido), o sistema deverá manipular o
 * código do produto, nome, unidade (kg, dz, m, un, cx, tn, etc...), valor
 * de venda e quantidade em estoque. O sistema deverá utilizar ponteiro 
 * para manipular a struct e apresentar um menu com as seguintes opções:
 * 0 – Sair
 * 1 – Cadastrar produto
 * 2 – Listar produtos cadastrados
 * 3 – Consultar produto pelo código
 * 4 – Vender produto (fornece o código e a quantidade de venda, o sistema
 * verifica se existe estoque suficiente e executa a venda atualizando a
 * quantidade em estoque).
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct produto {
    char nome[64];
    char unidade[24];
    double valor;
    unsigned int codigo;
    unsigned int estoque;
};

typedef struct produtos_lista {
    struct produto produto;
    struct produtos_lista *pproduto;
} Produtos;

const char* menu =					  \
    "0 - Sair\n"                                          \
    "1 - Cadastrar produto\n"                             \
    "2 - Listar produtos cadastrados\n"                   \
    "3 - Consultar produto pelo código\n"                 \
    "4 - Vender produto\n"                                \
    ": ";

void cadastrar(Produtos **produtos) {
    Produtos *px;
    px = (Produtos*)malloc(sizeof (Produtos));

    cout << "### Cadastro de Produto ###" << endl;
    cout << "> Nome: ";
    cin >> px->produto.nome;

    cout << "> Código: ";
    cin >> px->produto.codigo;    

    cout << "> Valor: R$ ";
    cin >> px->produto.valor;

    cout << "> Unidade: ";
    cin >> px->produto.unidade;

    cout << "> Estoque disponivel: ";
    cin >> px->produto.estoque;

    if ((*produtos) == NULL) {
	px->pproduto = NULL;
	(*produtos) = px;
    } else {
	px->pproduto = *produtos;
	(*produtos) = px;
    }
}

void listar_produtos(Produtos *produtos) {
    Produtos *p;
    cout.precision(2);
    cout << "### Lista de Produtos ###" << endl;
    for (p = produtos; p != NULL; p = p->pproduto) {
	cout << endl << "> Produto: " << p->produto.nome << '\n'
	     << "> Código: " << p->produto.codigo << '\n'
	     << "> Valor de venda: R$ " << fixed << p->produto.valor << '\n'
	     << "> Estoque: " << p->produto.estoque << " " << p->produto.unidade << '\n';
    }
}

struct produto *consultar_codigo(Produtos *produtos, unsigned int codigo) {
    Produtos *p;
    struct produto px;
    p = produtos;

    while (1) {
	if (p->produto.codigo == codigo) {
	    return &(p->produto);
	} else if (p->pproduto == NULL) {
	    return NULL;
	} else {
	    p = p->pproduto;
	}
    }
}

void mostra_codigo(Produtos *produtos) {
    struct produto* aux;
    unsigned int codigo;
    cout.precision(2);

    cout << "> Informe o código do produto: ";
    cin >> codigo;
    
    aux = consultar_codigo(produtos, codigo);
    if (aux == NULL) {
	cerr << "> Código inválido!!\n";
	return;
    }
    
    cout << "> Produto: " << aux->nome << '\n'
	 << "> Código: " << aux->codigo << '\n'
	 << "> Valor de venda: " << fixed << aux->valor << '\n'
	 << "> Estoque: " << aux->estoque << " " << aux->unidade << '\n';
}

void vende_produto(Produtos *produtos) {
    struct produto* aux;
    unsigned int codigo, quant_venda;

    cout << "> Informe o código do produto a venda: ";
    cin >> codigo;

    cout << "> Informe a ser vendida: ";
    cin >> quant_venda;

    aux = consultar_codigo(produtos, codigo);
    if (aux == NULL) {
	cerr << "> Código inválido\n";
	return;
    }

    if (aux->estoque >= quant_venda) {
	aux->estoque -= quant_venda;
	cout << "> Venda efetuada!!\n> Valor já subtraído ~> " << aux->estoque << '\n';
    } else {
	cerr << "> Estoque insuficiente!!\n> Valor de estoque disponível: " << aux->estoque << '\n';
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    Produtos *produtos;
    bool run;
    int es;

    produtos = NULL;
    run = true;
    while (run) {
	cout << menu;
	cin >> es;

	switch (es) {
	case 0:
	    run = false;
	    break;
	case 1:
	    cadastrar(&produtos);
	    break;
	case 2:
	    listar_produtos(produtos);
	    break;
	case 3:
	    mostra_codigo(produtos);
	    break;
	case 4:
	    vende_produto(produtos);
	    break;
	default:
	    cerr << "> Alternativa indisponivel!!\n";
	    break;
	}
	cout << '\n';
    }
    free(produtos);
    return 0;
}
