#include <iostream>
#include <cmath>

int main() {
	std::cout.precision(5);
	
	double a, b, c, deltaplus;
	std::cin >> a >> b >> c;
	
	deltaplus = b*b - 4*a*c;
	if ((deltaplus >= 0) && (2*a != 0)) {
		deltaplus = sqrt(deltaplus);
		std::cout << std::fixed;
		std::cout << "R1 = " << ((-b + deltaplus) / (2*a)) << std::endl << "R2 = " << ((-b - deltaplus) / (2*a)) << std::endl;
	}
	else
		std::cout << "Impossivel calcular" << std::endl;
	return 0;
}
