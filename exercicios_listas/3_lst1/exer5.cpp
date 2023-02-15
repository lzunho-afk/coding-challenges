/*
 * Crie uma função para calcular a soma de duas matrizes MxN de números reais alocadas
 * dinamicamente. A função deve retornar a matriz com a soma realizada. A implementação
 * deste programa deve considerar as dimensões fornecidas pelo usuário. Além disso, antes
 * de finalizar o programa, deve-se liberar a área de memória alocada.
*/

#include <iostream>
#include <ctime>

using namespace std;

float* sum_mtx(float *p_mtx1, float *p_mtx2, int m, int n) {
    for (int i = 0; i < m*n; i++) {
        *(p_mtx1 + i) = *(p_mtx1 + i) + *(p_mtx2 + i);
    }
    return p_mtx1;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    float *p_mtx1, *p_mtx2, *res_mtx;
    unsigned int m, n;
    cout << "Informe o valor de M (MxN): ";
    cin >> m;
    cout << "Informe o valor de N (MxN): ";
    cin >> n;
    p_mtx1 = new float[m*n];
    p_mtx2 = new float[m*n];

    // Matriz 1
    cout << "Mtx1 => {\n";
    for (int i = 0; i < m*n; i++) {
        if (i % n == 0) {
            cout << "\t},\n";
        }
        *(p_mtx1 + i) = rand() % 9999 / 100.0 + 1;
        cout << "\t\t" << *(p_mtx1 + i) << ",\n";
    }
    cout << "}\n";

    // Matriz 2
    cout << "Mtx2 => {\n";
    for (int i = 0; i < m*n; i++) {
        if (i % n == 0) {
            cout << "\t},\n";
        }
        *(p_mtx2 + i) = rand() % 9999 / 100.0 + 1;
        cout << "\t\t" << *(p_mtx2 + i) << ",\n";
    }
    cout << "}\n";

    // Soma
    res_mtx = sum_mtx(p_mtx1, p_mtx2, m, n);

    // Dump
    cout << "Matrix => {\n";
    cout << "\t{\n";
    for (int i = 0; i < m*n; i++) {
        if (i % n == 0 && i != 0) {
            cout << "\t},\n";
        }
        cout << "\t\t" << *(res_mtx + i) << "\n";
    }
    cout << "\t}\n}\n";

    delete[] res_mtx, p_mtx1, p_mtx2;
    return 0;
}
