#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(2);

    double sal, real;
    int per;
    cin >> sal;
    if (sal <= 400.00) {
        per = 15;
        real = sal*(per/100.00);
        sal = sal + real;
    } else if (sal <= 800.00) {
        per = 12;
        real = sal*(per/100.00);
        sal = sal + real;
    } else if (sal <= 1200.00) {
        per = 10;
        real = sal*(per/100.00);
        sal = sal + real;
    } else if (sal <= 2000.00) {
        per = 7;
        real = sal*(per/100.00);
        sal = sal + real;
    } else if (sal > 2000.00) {
        per = 4;
        real = sal*(per/100.00);
        sal = sal + real;
    }
    cout << "Novo salario: " << fixed << sal << endl << "Reajuste ganho: " << fixed << real << endl << "Em percentual: " << per << " %" << endl;
    return 0;
}
