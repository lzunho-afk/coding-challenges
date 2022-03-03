#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double vals[3], aux;
    cin >> vals[0] >> vals[1] >> vals[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (vals[i] > vals[j]) {
                aux = vals[i];
                vals[i] = vals[j];
                vals[j] = aux;
            }
        }
    }
    if (vals[0] >= vals[1] + vals[2]) 
        cout << "NAO FORMA TRIANGULO" << endl;
    else if (vals[0]*vals[0] == vals[1]*vals[1] + vals[2]*vals[2]) 
        cout << "TRIANGULO RETANGULO" << endl;
    else if (vals[0]*vals[0] > vals[1]*vals[1] + vals[2]*vals[2])
        cout << "TRIANGULO OBTUSANGULO" << endl;
    else if (vals[0]*vals[0] < vals[1]*vals[1] + vals[2]*vals[2])
        cout << "TRIANGULO ACUTANGULO" << endl;

    if (vals[0] == vals[1]) {
        if (vals[1] == vals[2]) {
            cout << "TRIANGULO EQUILATERO" << endl;
        } else
            cout << "TRIANGULO ISOSCELES" << endl;
    } else if (vals[1] == vals[2] || vals[0] == vals[2]) {
        cout << "TRIANGULO ISOSCELES" << endl;
    }
    return 0;
}
