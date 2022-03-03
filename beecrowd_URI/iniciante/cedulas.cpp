#include <iostream>

using namespace std;

int main() {
  long long int n;
  unsigned int aux, cem, cinq, vin, dez, cinc, dois, um;
  cin >> n;
	
  cem = n/100;
  aux = n%100;
  cinq = aux/50;
  aux = aux%50;
  vin = aux/20;
  aux = aux%20;
  dez = aux/10;
  aux = aux%10;
  cinc = aux/5;
  aux = aux%5;
  dois = aux/2;
  aux = aux%2;
  um = aux/1;
  aux = aux%1;
	
  cout << n << endl << cem << " nota(s) de R$ 100,00" << endl << cinq << " nota(s) de R$ 50,00" << endl << vin << " nota(s) de R$ 20,00" << endl << dez << " nota(s) de R$ 10,00" << endl << cinc << " nota(s) de R$ 5,00" << endl << dois << " nota(s) de R$ 2,00" << endl << um << " nota(s) de R$ 1,00" << endl;
  return 0;
}
