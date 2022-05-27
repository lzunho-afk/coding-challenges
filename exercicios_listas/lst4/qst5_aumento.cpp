/*
Os funcionários de uma empresa receberam um aumento de salário:
1) Técnicos: 50% 2) Gerentes: 30% 3) Demais: 20%
Escreva um algoritmo que receba como entrada o salário atual e o cargo do funcionário, e apresente o
novo salário após o aumento. Imprima também o cargo, de acordo com a entrada digitada
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    std::cout.precision(2);

    int cargo;
    double sal;

    std::cout << "Por favor, informe o cargo seguido pelo salário: ";
    std::cin >> cargo >> sal;

    switch (cargo) {
    case 1:
        sal += (sal*(50.00/100.00));
        std::cout << "O funcionário TÉCNICO tem um novo salário de R$ " << std::fixed << sal << "\n";
        break;
    case 2:
        sal += (sal*(30.00/100.00));
        std::cout << "O funcionário GERENTE tem um novo salário de R$ " << std::fixed << sal << "\n";
        break;
    case 3:
        sal += (sal*(20.00/100.00));
        std::cout << "O funcionário tem um novo salário de R$ " << std::fixed << sal << "\n";
        break;
    default:
        std::cerr << "Código invalido!!\n";
        return 1;
    }
    return 0;
}
