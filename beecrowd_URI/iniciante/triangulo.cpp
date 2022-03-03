#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(1);

    double a, b, c;
    cin >> a >> b >> c;
    if (a+b > c && a+c > b && c+b > a)
        cout << "Perimetro = " << fixed << (a+b+c) << endl;
    else
        cout << "Area = " << fixed << (((a+b)*c)/2.0) << endl;
    return 0;
}
