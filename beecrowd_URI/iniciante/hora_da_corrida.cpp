#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned long long int num_placas, num_voltas, aux;
	cin >> num_voltas >> num_placas;
	num_placas *= num_voltas;
	
	for (int i = 1; i <= 8; i++) {
		aux = ceil((double)(num_placas * i) / (double)10);
		cout << aux << " ";
	}
	aux = ceil((double)(num_placas * 9) / (double)10);
	cout << aux << endl;
	return 0;
}
