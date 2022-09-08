#include <iostream>

using namespace std;

int main(void) {
    bool mA, mI, n, inv, tam;
    string passw;

    while (getline(cin, passw)) {
        mA = mI = n = inv = tam = false;
        for (int i = 0; i < passw.length(); i++) {
            if (!isalnum(passw[i]) || passw.length() < 6 || passw.length() > 32) {
                inv = true;
                break;
            } else if (isupper(passw[i]))
                mA = true;
            else if (islower(passw[i]))
                mI = true;
            else if (isdigit(passw[i]))
                n = true;
        }
        if (!inv && mA && mI && n) {
            cout << "Senha valida." << endl;
        } else {
            cout << "Senha invalida." << endl;
        }
    }
    return 0;
}
