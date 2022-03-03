#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(1);

    double n1,n2,n3,n4;
    double aux, p;
    cin >> n1 >> n2 >> n3 >> n4;
    aux = (n1*2+n2*3+n3*4+n4*1)/10;
    cout << "Media: " << fixed << aux << endl;

    if (aux < 5)
        cout << "Aluno reprovado." << endl;
    else if (aux >= 5 && aux < 7) {
        cout << "Aluno em exame." << endl;
        cin >> p;
        cout << "Nota do exame: " << fixed << p << endl;

        aux = (aux+p)/2.0;
        if (aux > 5) cout << "Aluno aprovado." << endl;
        else cout << "Aluno reprovado." << endl;

        cout << "Media final: " << fixed << aux << endl;
    } else
        cout << "Aluno aprovado." << endl;
    return 0;
}
