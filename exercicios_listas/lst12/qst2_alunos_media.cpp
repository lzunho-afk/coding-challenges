/*
 * Escreva uma função que recebe as 3 notas de um aluno por parâmetro 
 * e uma letra. Se a letra for A, a função calcula a média aritmética
 * das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e
 * 2) e se for H, a sua média harmônica.
 */

#include <iostream>

using namespace std;

void media(float n1, float n2, float n3, char method)
{
    cout.precision(2);
    double med;

    switch (method) 
    {
        case 'A':
            med = (n1+n2+n3)/3.00;
            cout << "A média ARITMÉTICA das notas é " << fixed << med << endl;
            break;
        case 'P':
            med = (n1*5.00 + n2*3.00 + n3*2.00)/10.00;
            cout << "A média PONDERADA das notas é " << fixed << med << endl;
            break;
        case 'H':
            med = 3.00/((1.00/n1)+(1.00/n2)+(1.00/n3));
            cout << "A média HARMONICA das notas é " << fixed << med << endl;
            break;
        default:
            cerr << "Método de entrada inválido! method -> " << fixed << method << endl;
            exit(EXIT_FAILURE);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3;
    char method;

    cout << "Por favor, informe as três notas do aluno: ";
    cin >> n1 >> n2 >> n3;
    
    cout << "Método (A/P/H): ";
    cin >> method;

    media(n1, n2, n3, method);
    return 0;
}

