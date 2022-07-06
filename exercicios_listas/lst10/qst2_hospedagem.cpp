/*
    Faça um programa para gerenciar as hospedagens de um hotel, contendo 12 quartos disponíveis.
Para gerenciar os quartos, crie um vetor de inteiros V[12] e atribua zero para todas as posições (todos
os quartos vagos).
    O programa deverá apresentar um menu com as seguintes opções:
        a) Efetuar reserva:
            - O programa deverá ler o número n do quarto e a quantidade q de hóspedes.
            - Armazenar a reserva no vetor: V[n] = q;
        b) Listar todos os quartos
            - Percorrer o vetor e mostrar a quantidade de hóspedes de cada quarto.
        c) Listar os quartos vagos
            - Percorrer o vetor e mostrar o número dos quartos em que a quantidade de hóspedes é zero.
        d) Mostrar o total de pessoas hospedadas no hotel
            - Efetuar a soma de todos os elementos do vetor.
        e) Efetuar saída:
            - O programa deverá ler o número n do quarto.
            - Atribuir zero para quantidade de hóspedes do quarto n: V[n] = 0;
        f) Listar quartos ocupados cujo número de hóspedes seja maior ou igual a um valor inteiro “x”,
        sendo que esse valor deve ser informado pelo usuário.
        Observações:
            - Para sair do menu (encerrar o programa) pergunte para o usuário se ele deseja sair do
            programa.
            - Ao efetuar uma reserva de um quarto já ocupado o programa deverá emitir uma mensagem de
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
                << "5 - Efetuar saída\n" << "6 - Listar quartos ocupados por mais ou x pessoas\n" << ':';
        std::cin >> es;
        switch(es)
        {
        case 1:
            std::cout << "Número: ";
            std::cin >> n;
            std::cout << "Hospedes: ";
            std::cin >> q;

            if (v[n] != 0)
            {
                std::cerr << "Quarto já hospedado!!\n";
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
            std::cout << "Número: ";
            std::cin >> n;
            v[n] = 0;
            std::cout << "Saída Efetuada no Quarto " << n << "!\n";
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
            std::cerr << "Opção Invalida!!" << std::endl;
            break;
        }

        std::cout << "Deseja sair do programa? (s/n) ";
        std::cin >> ch;
        if (ch == 's') break;
    }
    return 0;
}
