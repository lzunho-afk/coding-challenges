#include <iostream>

using namespace std;

int abs(int h) {
	if (h < 0) return (h*(-1));
	else return (h);
}

int main() {
	int x, y, z, aux;
	cin >> x >> y >> z;
	aux = (x+y+abs(x - y))/2;
	
	cout << ((aux+z+abs(aux - z))/2) << " eh o maior" << endl;
	return 0;
}
