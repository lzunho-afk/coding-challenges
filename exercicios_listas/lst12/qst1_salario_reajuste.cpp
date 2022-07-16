/*
 * Crie uma função que recebe como parâmetros o salário de um funcionário e o 
 * percentual de reajuste e retorna o salário reajustado. No programa principal,
 * leia o salário do funcionário e o percentual de reajuste, em seguida, chame
 * a função para calcular o reajuste do salário e imprima o valor do salário
 * reajustado. 
 */

#include <iostream>

using namespace std;

double reajuste(double sal, double per)
{
    return (sal+(sal*(per/100.00)));
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);
    double sal, per;

    cout << "Informe o salário do funcionário: R$ ";
    cin >> sal;
    cout << "Informe o percentual de reajuste: ";
    cin >> per;

    sal = reajuste(sal, per);
    cout << "O salário reajustado é de R$ " << fixed << sal << endl;
    return 0;
}
