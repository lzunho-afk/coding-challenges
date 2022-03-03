#include <iostream>

using namespace std;

int main() {
	int d, m, a;
	cin >> d;
	
	a = d/365;
	d -= a*365;
	
	m = d/30;
	d -= m*30;
	
	cout << a << " ano(s)" << endl << m << " mes(es)" << endl << d << " dia(s)" << endl;
	
	return 0;
}
