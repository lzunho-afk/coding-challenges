#include <iostream>
#include <vector>

#define TAM 10

using namespace std;

int main(void) {
    int input;
    vector <int> vet_x(TAM, 1);

    for (int i = 0; i < TAM; i++) {
        cin >> input;
        if (input <= 0) continue;
        vet_x[i] = input;
    }
    for (int i = 0; i < TAM; i++)
        cout << "X[" << i << "] = " << vet_x[i] << endl;
    
    return 0;
}
