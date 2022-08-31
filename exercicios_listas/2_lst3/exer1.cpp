/*
Escreva um programa, que utilizando funções e passagem de parâmetro, calcule e mostre
a área de um trapézio. Sabendo que: A = (base maior + base menor) * altura) / 2;
O programa deverá ter 3 funções: leitura, calcula, mostra.
*/

#include <iostream>

using namespace std;

const char* header = { "###<-- Área do Trapézio -->###\n\n" };

void leitura(double &bm, double &bM, double &h);
double calcula(double bm, double bM, double h);
void mostra(double area);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    double bm, bM, h, area;

    cout << header;
    leitura(bm, bM, h);

    area = calcula(bm, bM, h);
    mostra(area);
    return 0;
}

void leitura(double &bm, double &bM, double &h) {
    cout << "Informe a base maior do trapézio: ";
    cin >> bM;
    cout << "Informe a base menor do trapézio: ";
    cin >> bm;
    cout << "Informe a altura do trapézio: ";
    cin >> h;
}

double calcula(double bm, double bM, double h) {
    double calc;
    calc = ((bM + bm) * (h * 1.00)) / 2.00;
    return calc;
}

void mostra(double area) {
    cout.precision(2);
    cout << "Área = " << fixed << area << endl;
}
