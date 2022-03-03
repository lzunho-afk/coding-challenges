/* https://www.beecrowd.com.br/judge/pt/problems/view/1051
 * 03-03-2022
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout.precision(2);

  double sl, val, aux, n, p;

  cin >> sl;
  if (sl <= 2000.00) {
    cout << "Isento" << endl;
    return 0;
  }
  val = 0;
  for (;;) {
    if (sl > 4500.00) {
      aux = sl - 4500.00;
      val += aux * (28.00/100.00);
      sl = 4500.00;
    } else if (sl > 3000.00) {
      aux = sl - 3000.00;
      val += aux * (18.00/100.00);
      sl = 3000.00;
    } else if (sl > 2000.00) {
      aux = sl - 2000.00;
      val += aux * (8.00/100.00);
      sl = 2000.00;
    } else {
      break;
    }
  }
  cout << fixed;
  cout << "R$ " << val << endl;
  return 0;
}
