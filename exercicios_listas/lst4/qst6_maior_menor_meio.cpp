/*
Escreva um algoritmo que leia três números: A, B e C. Encontrar e mostrar o maior, o menor e o do
meio entre os três números. Mostre os números em ordem crescente.
*/

#include <iostream>

int main(void) {
    setlocale(LC_ALL, "pt_BR");

    int x, y, z, aux;

    std::cout << "Por favor, informe os três números: ";
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

    std::cout << x << " é o MAIOR\n"
	      << y << " é o DO MEIO\n"
	      << z << " é o MENOR\n";
    return 0;
}
