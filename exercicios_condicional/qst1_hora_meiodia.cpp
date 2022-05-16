/*
Escreva um programa que receba um valor referente a uma hora, caso o valor n�o esteja no intervalo
00 at� as 24 informar que n�o � uma hora v�lida, caso esteja no intervalo calcular e informar quantas
horas faltam ou j� passaram das 12 horas.
Teste 1: 32
Teste 2: 2
Teste 3: 18
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    std::cout.precision(2);

    double hora, aux;
    std::cout << "Informe a hora: ";
    std::cin >> hora;

    aux = std::abs(hora - 12);
    if (!(hora >= 0 && hora < 24)) {
        std::cout << "Hora invalida\n";
    } else if (hora > 12) {
        std::cout << "Passaram " << std::fixed << aux << " horas do meio-dia\n";
    } else if (hora < 12) {
        std::cout << "Faltam " << std::fixed << aux << " horas para o meio-dia\n";
    } else {
        std::cout << "� meio-dia\n";
        return 1;
    }
    return 0;
}
