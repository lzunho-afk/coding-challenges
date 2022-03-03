#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(2);

    int cod, count;

    cin >> cod >> count;
    switch (cod) {
        case 1:
            cout << "Total: R$ " << fixed << 4.00*count << endl;
            break;
        case 2:
            cout << "Total: R$ " << fixed << 4.50*count << endl;
            break;
        case 3:
            cout << "Total: R$ " << fixed << 5.00*count << endl;
            break;
        case 4:
            cout << "Total: R$ " << fixed << 2.00*count << endl;
            break;
        case 5:
            cout << "Total: R$ " << fixed << 1.50*count << endl;
            break;
    }
    return 0;
}
