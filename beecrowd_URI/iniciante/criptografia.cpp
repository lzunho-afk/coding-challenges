#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tZc;
    cin >> n;
    cin.ignore();

    string txt;
    char aux;
    for (int i = 0; i < n; i++) {
        getline(cin, txt);

        tZc = txt.size();
        for (int j = 0; j < tZc; j++) {
            if (isalpha(txt[j])) {
                txt[j] += 3;
            }
        }
        for (int j = 0; j < tZc/2; j++) {
            aux = txt[j];
            txt[j] = txt[tZc-(j+1)];
            txt[tZc-(j+1)] = aux;
        }

        for (int j = tZc/2; j < tZc; ++j) {
            txt[j] -= 1;
        }
        cout << txt << endl;
    }
    
    return 0;
}
