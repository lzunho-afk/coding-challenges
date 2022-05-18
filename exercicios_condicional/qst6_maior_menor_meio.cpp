/*
Escreva um algoritmo que leia tr�s n�meros: A, B e C. Encontrar e mostrar o maior, o menor e o do
meio entre os tr�s n�meros. Mostre os n�meros em ordem crescente.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "pt_BR");

    int x, y, z, aux;

    std::cout << "Por favor, informe os tr�s n�meros: ";
    std::cin >> x >> y >> z;

    if (x < y) {
      aux = x;
      x = y;
      y = aux;
    }
    if (x < z) {
      aux = x;
      x = z;
      z = aux;
    }
    if (y < z) {
      aux = y;
      y = z;
      z = aux;
    }

    std::cout << x << " � o MAIOR\n"
	      << y << " � o DO MEIO\n"
	      << z << " � o MENOR\n";
    return 0;
}
