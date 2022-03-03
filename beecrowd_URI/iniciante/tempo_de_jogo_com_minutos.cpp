#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, h2, m1, m2;
    int aux1, aux2;
    int tm, th;
    cin >> h1 >> m1 >> h2 >> m2;

    aux1 = h1 * 60 + m1;
    aux2 = h2 * 60 + m2;
    
    if (aux1 >= aux2) {
        aux2 += 24 * 60;
    }
    tm = abs(aux2 - aux1);

    th = tm/60;
    tm %= 60;
    
    cout << "O JOGO DUROU " << th << " HORA(S) E " << tm << " MINUTO(S)" << endl;

    return 0;
}
