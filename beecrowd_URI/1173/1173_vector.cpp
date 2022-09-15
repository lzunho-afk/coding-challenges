#include <iostream>
#include <vector>

#define TAM 9

using namespace std;

int main(void) {
    int input;
    vector <unsigned int> vet_n(TAM);

    cin >> input;
    vet_n.insert(vet_n.begin(), input);

    cout << "N[0] = " << vet_n[0] << endl;
    for (int i = 1; i <= TAM; i++) {
        vet_n[i] = vet_n[i-1]*2;
        cout << "N[" << i << "] = " << vet_n[i] << endl;
    }
    return 0;
}
