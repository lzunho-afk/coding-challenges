#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << (a%b==0 || b%a==0 ? "Sao Multiplos" : "Nao sao Multiplos") << endl;
    return 0;
}
