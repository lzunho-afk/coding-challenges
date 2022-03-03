#include <iostream>

using namespace std;

int main() {
	int s, h, m;
	cin >> s;
	// 140153
	m = s/60;
	h = m/60;
	m -= (h*60);
	s -= (h*60 + m)*60;
	
	cout << h << ":" << m << ":" << s << endl;
	return 0;
}
