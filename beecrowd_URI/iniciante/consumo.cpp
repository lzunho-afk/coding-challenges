#include <iostream>

using namespace std;

int main() {
	cout.precision(3);
	int kms;
	double l;
	cin >> kms >> l;
	cout << fixed << (kms/l) << " km/l" << endl;
	return 0;
}
