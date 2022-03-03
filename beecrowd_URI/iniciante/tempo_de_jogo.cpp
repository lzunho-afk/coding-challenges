#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int hi, hf;
    cin >> hi >> hf;
    if (hf == hi) 
        cout << "O JOGO DUROU " << 24 << " HORA(S)" << endl;
    else if (hf < hi)
        cout << "O JOGO DUROU " << ((24-hi)+hf) << " HORA(S)" << endl;
    else
        cout << "O JOGO DUROU " << abs(hi-hf) << " HORA(S)" << endl;
    return 0;
}
