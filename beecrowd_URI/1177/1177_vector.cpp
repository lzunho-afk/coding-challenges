#include <iostream>
#include <vector>

#define TAM 1000

using namespace std;

int main(void) {
    int t, i;
    bool run = true;
    vector <int> vet_n(TAM);

    cin >> t;
    i = 0;
    while (run) {
        for (int j = 0; j < t; j++) {
            if (i + 1 != TAM) {
                cout << "N[" << i << "] = " << j << endl;
                i++;
            } else {
                run = false;
                break;
            }
        }
    }
    return 0;
}
