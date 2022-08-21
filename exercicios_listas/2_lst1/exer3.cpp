/*
 * Escreva um programa que receba a altura (h), o sexo de uma pessoa 
 * (M – Masculino, F – Feminino) e o seu peso atual, após o sistema 
 * deverá calcular o peso ideal, utilizando as seguintes fórmulas:
 *  - Homens: (72.7 * h) - 58
 *  - Mulheres: (62.1 * h) - 44.7
 *  Considera-se que a pessoa está no peso ideal se o seu peso atual 
 *  encontra-se em uma margem de -3kg do peso ideal ou +3kg do peso ideal.
 *  Ao Final o sistema deverá exibir se o usuário está abaixo, dentro 
 *  do peso ideal, ou acima dopeso ideal.
*/

#include <iostream>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    double height, pes, pes_ideal;
    char sex;

    cout << "Por favor, informe sua altura: ";
    cin >> height;
    cout << "Sexo (M/F): ";
    cin >> sex;
    cout << "Peso (kg): ";
    cin >> pes;

    if (sex == 'M') {
        pes_ideal = (72.7 * height) - 58.00;
    } else if (sex == 'F') {
        pes_ideal = (62.1 * height) - 44.70;
    } else {
        cerr << "Entrada incorreta!" << endl;
        return 1;
    }

    if (pes <= pes_ideal+3 && pes >= pes_ideal-3) {
        cout << "Você está DENTRO do peso ideal!" << endl;
    } else if (pes > pes_ideal+3) {
        cout << "Você está ACIMA do peso ideal!" << endl;
    } else {
        cout << "Você está ABAIXO do peso ideal!" << endl;
    }
    return 0;
}
