#include <iostream>

using namespace std;

int main(void) {
    int count;
    string input, comp, aux;

    cin >> count;
    while (count != 0) {
        cin >> input >> comp;

        if (input == comp) {
            cout << "encaixa" << endl;
            count--;
            continue;
        } else if (input.length() <= comp.length()) {
            cout << "nao encaixa" << endl;
            count--;
            continue;
        }

        if (input.substr((input.length() - comp.length()), comp.length()) == comp) {
            cout << "encaixa" << endl;
            count--;
            continue;
        } else {
            cout << "nao encaixa" << endl;
        }
        count--;
    }

    return 0;
}
