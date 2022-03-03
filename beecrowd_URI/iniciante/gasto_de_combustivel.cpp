#include <iostream>

using namespace std;

int main() {
	cout.precision(3);
	int v, t;
	cin >> t >> v;
	cout << fixed << ((v*t)/12.0) << endl;
	return 0;
}
