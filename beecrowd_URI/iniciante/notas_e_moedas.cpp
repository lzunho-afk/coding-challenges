#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double m;
  int m_int, cem, cinq, vint, dez, cinc, dois; // nota
  int um, cinq_c, vintecinc_c, dez_c, cinc_c, um_c; // moeda
  
  cin >> m;
  m_int = int(m);
  m = round(m*100);
  m -= m_int*100;
	
  cem = m_int/100;
  m_int -= cem*100;
  cinq = m_int/50;
  m_int -= cinq*50;
  vint = m_int/20;
  m_int -= vint*20;
  dez = m_int/10;
  m_int -= dez*10;
  cinc = m_int/5;
  m_int -= cinc*5;
  dois = m_int/2;
  m_int -= dois*2;
  um = m_int/1;
	
  cinq_c = m/50;
  m -= cinq_c*50;
  vintecinc_c = m/25;
  m -= vintecinc_c*25;
  dez_c = m/10;
  m -= dez_c*10;
  cinc_c = m/5;
  m -= cinc_c*5;
  um_c = m/1;
	
  cout << 
    "NOTAS:" << endl <<
    cem << " nota(s) de R$ 100.00" << endl <<
    cinq << " nota(s) de R$ 50.00" << endl <<
    vint << " nota(s) de R$ 20.00" << endl <<
    dez << " nota(s) de R$ 10.00" << endl <<
    cinc << " nota(s) de R$ 5.00" << endl <<
    dois << " nota(s) de R$ 2.00" << endl <<
    "MOEDAS:" << endl <<
    um << " moeda(s) de R$ 1.00" << endl <<
    cinq_c << " moeda(s) de R$ 0.50" << endl <<
    vintecinc_c << " moeda(s) de R$ 0.25" << endl <<
    dez_c << " moeda(s) de R$ 0.10" << endl <<
    cinc_c << " moeda(s) de R$ 0.05" << endl <<
    um_c << " moeda(s) de R$ 0.01" << endl;
  return 0;
}
