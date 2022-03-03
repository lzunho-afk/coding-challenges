#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x;
    cin >> x;
    if (x >= 0 && x <= 100) {
        if (x > 50) {
            if (x > 75) {
                cout << "Intervalo (75,100]" << endl;
                return 0;
            }
            cout << "Intervalo (50,75]" << endl;
        } else if (x > 25)
            cout << "Intervalo (25,50]" << endl;
        else 
            cout << "Intervalo [0,25]" << endl;
    } else {
        cout << "Fora de intervalo" << endl;
    }
    return 0;
}
