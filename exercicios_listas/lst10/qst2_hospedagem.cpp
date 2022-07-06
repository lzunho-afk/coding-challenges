/*
    Fa�a um programa para gerenciar as hospedagens de um hotel, contendo 12 quartos dispon�veis.
Para gerenciar os quartos, crie um vetor de inteiros V[12] e atribua zero para todas as posi��es (todos
os quartos vagos).
    O programa dever� apresentar um menu com as seguintes op��es:
        a) Efetuar reserva:
            - O programa dever� ler o n�mero n do quarto e a quantidade q de h�spedes.
            - Armazenar a reserva no vetor: V[n] = q;
        b) Listar todos os quartos
            - Percorrer o vetor e mostrar a quantidade de h�spedes de cada quarto.
        c) Listar os quartos vagos
            - Percorrer o vetor e mostrar o n�mero dos quartos em que a quantidade de h�spedes � zero.
        d) Mostrar o total de pessoas hospedadas no hotel
            - Efetuar a soma de todos os elementos do vetor.
        e) Efetuar sa�da:
            - O programa dever� ler o n�mero n do quarto.
            - Atribuir zero para quantidade de h�spedes do quarto n: V[n] = 0;
        f) Listar quartos ocupados cujo n�mero de h�spedes seja maior ou igual a um valor inteiro �x�,
        sendo que esse valor deve ser informado pelo usu�rio.
        Observa��es:
            - Para sair do menu (encerrar o programa) pergunte para o usu�rio se ele deseja sair do
            programa.
            - Ao efetuar uma reserva de um quarto j� ocupado o programa dever� emitir uma mensagem de
            erro.
*/

#include <iostream>

#define TAMQ 12

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int v[TAMQ], es, n, q;
    char ch;
    for (int i = 0; i < TAMQ; i++) v[i] = 0;

    while (true)
    {
        std::cout << "1 - Efetuar reserva\n" << "2 - Listar todos os quartos\n"
                << "3 - Listar os quartos vagos\n" << "4 - Mostrar o total de pessoas hospedadas\n"
                << "5 - Efetuar sa�da\n" << "6 - Listar quartos ocupados por mais ou x pessoas\n" << ':';
        std::cin >> es;
        switch(es)
        {
        case 1:
            std::cout << "N�mero: ";
            std::cin >> n;
            std::cout << "Hospedes: ";
            std::cin >> q;

            if (v[n] != 0)
            {
                std::cerr << "Quarto j� hospedado!!\n";
                break;
            }
            v[n] = q;
            std::cout << "\n";
            break;
        case 2:
            std::cout << "Hotel {\n";
            for (int i = 0; i < TAMQ; i++)
                std::cout << "\tQuarto " << i << " ~> " << v[i] << ',' << std::endl;
            std::cout << "}\n\n";
            break;
        case 3:
            std::cout << "Vazios {\n";
            for (int i = 0; i < TAMQ; i++)
            {
                if (v[i] == 0)
                std::cout << "\tQuarto " << i << " ~> " << v[i] << " vazio,\n" << std::endl;
            }
            std::cout << "}\n";
            break;
        case 4:
            q = 0;
            for (int i = 0; i < TAMQ; i++) q += v[i];
            std::cout << "Total de Hospedes ~> " << q << "\n\n";
            break;
        case 5:
            std::cout << "N�mero: ";
            std::cin >> n;
            v[n] = 0;
            std::cout << "Sa�da Efetuada no Quarto " << n << "!\n";
            break;
        case 6:
            std::cout << "X: ";
            std::cin >> n;
            std::cout << "Quartos >= " << n << " {\n";
            for (int i = 0; i < TAMQ; i++)
            {
                if (v[i] >= n)
                    std::cout << "\tQuarto " << i << " ~> " << v[i] << ",\n";
            }
            std::cout << "}\n";
            break;
        default:
            std::cerr << "Op��o Invalida!!" << std::endl;
            break;
        }

        std::cout << "Deseja sair do programa? (s/n) ";
        std::cin >> ch;
        if (ch == 's') break;
    }
    return 0;
}
