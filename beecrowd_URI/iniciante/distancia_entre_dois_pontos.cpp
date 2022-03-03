#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout.precision(4);
	
	double x1, y1, x2, y2, xd, yd;
	cin >> x1 >> y1 >> x2 >> y2;
	
	xd = x2-x1;
	yd = y2-y1;
	cout << fixed << sqrt((xd*xd)+(yd*yd)) << endl;
	return 0;
}
