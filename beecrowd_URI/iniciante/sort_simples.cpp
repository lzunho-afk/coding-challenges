#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n[3], vet_a[3], aux;
    cin >> n[0] >> n[1] >> n[2];
    vet_a[0] = n[2];
    vet_a[1] = n[1];
    vet_a[2] = n[0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (n[i] > n[j]) {
                aux = n[i];
                n[i] = n[j];
                n[j] = aux;
            }
        }
    }
    for (int i = 2; i >= 0; i--) cout << n[i] << endl;
    cout << endl;
    for (int i = 2; i >= 0; i--) cout << vet_a[i] << endl;
    return 0;
}
