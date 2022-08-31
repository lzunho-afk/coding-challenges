/*
Escreva um programa, que utilizando fun��es e passagem de par�metro, calcule e mostre
a �rea de um trap�zio. Sabendo que: A = (base maior + base menor) * altura) / 2;
O programa dever� ter 3 fun��es: leitura, calcula, mostra.
*/

#include <iostream>

using namespace std;

const char* header = { "###<-- �rea do Trap�zio -->###\n\n" };

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
    cout << "Informe a base maior do trap�zio: ";
    cin >> bM;
    cout << "Informe a base menor do trap�zio: ";
    cin >> bm;
    cout << "Informe a altura do trap�zio: ";
    cin >> h;
}

double calcula(double bm, double bM, double h) {
    double calc;
    calc = ((bM + bm) * (h * 1.00)) / 2.00;
    return calc;
}

void mostra(double area) {
    cout.precision(2);
    cout << "�rea = " << fixed << area << endl;
}
