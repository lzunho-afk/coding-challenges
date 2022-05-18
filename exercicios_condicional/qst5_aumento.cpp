/*
Os funcion�rios de uma empresa receberam um aumento de sal�rio:
1) T�cnicos: 50% 2) Gerentes: 30% 3) Demais: 20%
Escreva um algoritmo que receba como entrada o sal�rio atual e o cargo do funcion�rio, e apresente o
novo sal�rio ap�s o aumento. Imprima tamb�m o cargo, de acordo com a entrada digitada
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    std::cout.precision(2);

    int cargo;
    double sal;

    std::cout << "Por favor, informe o cargo seguido pelo sal�rio: ";
    std::cin >> cargo >> sal;

    switch (cargo) {
    case 1:
        sal += (sal*(50.00/100.00));
        std::cout << "O funcion�rio T�CNICO tem um novo sal�rio de R$ " << std::fixed << sal << "\n";
        break;
    case 2:
        sal += (sal*(30.00/100.00));
        std::cout << "O funcion�rio GERENTE tem um novo sal�rio de R$ " << std::fixed << sal << "\n";
        break;
    case 3:
        sal += (sal*(20.00/100.00));
        std::cout << "O funcion�rio tem um novo sal�rio de R$ " << std::fixed << sal << "\n";
        break;
    default:
        std::cerr << "C�digo invalido!!\n";
        return 1;
    }
    return 0;
}
