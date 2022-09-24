/*
 * Crie um programa que manipule uma estrutura capaz de descrever um mês do ano. A
 * estrutura deve conter os seguintes membros: número do mês, nome por extenso do mês,
 * abreviatura com as três iniciais do mês e o número de dias do mês (validar o mês de fevereiro
 * em caso de ano bissexto).
 * Após alimentar os dados para esta estrutura o programa deve solicitar um dia e um mês
 * qualquer e deverá mostrar o total de dias já transcorrido no corrente ano, o dia e mês
 * informado e os dados (nome, abreviatura, total de dias) referente ao mês informado, caso seja
 * informado dia ou mês inválido deverá apresentar uma mensagem com tal informação.
*/

#include <iostream>

using namespace std;

struct mes {
    string nome;
    string abrev;
    short n_mes;
    short n_dias;
};

void nome_mes(struct mes* m) {
    switch (m->n_mes) {
        case 1:
            m->nome = "Janeiro";
            m->abrev = "Jan";
            break;
        case 2:
            m->nome = "Fevereiro";
            m->abrev = "Fev";
            break;
        case 3:
            m->nome = "Março";
            m->abrev = "Mar";
            break;
        case 4:
            m->nome = "Abril";
            m->abrev = "Abr";
            break;
        case 5:
            m->nome = "Maio";
            m->abrev = "Maio";
            break;
        case 6:
            m->nome = "Junho";
            m->abrev = "Jun";
            break;
        case 7:
            m->nome = "Julho";
            m->abrev = "Jul";
            break;
        case 8:
            m->nome = "Agosto";
            m->abrev = "Ago";
            break;
        case 9:
            m->nome = "Setembro";
            m->abrev = "Set";
            break;
        case 10:
            m->nome = "Outubro";
            m->abrev = "Out";
            break;
        case 11:
            m->nome = "Novembro";
            m->abrev = "Nov";
            break;
        case 12:
            m->nome = "Dezembro";
            m->abrev = "Dez";
            break;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    mes ano[12];
    int dia, mes, nc_dias;

    time_t ttime = time(NULL);
    struct tm tm = *localtime(&ttime);
    int at_year = tm.tm_year + 1900;

    cout << "[*] Considerando o ano de '" << at_year << "' para realização de calculos" << endl;
    for (int i = 0; i < 12; i++) {
        ano[i].n_mes = i + 1;
        if (i == 1) {
            if (at_year % 100 != 0 && at_year % 4 == 0) {
                ano[i].n_dias = 29;
            } else {
                ano[i].n_dias = 28;
            }
        } else if (i < 7) {
            if (i % 2 == 0) {
                ano[i].n_dias = 31;
            } else {
                ano[i].n_dias = 30;
            }
        } else {
            if (i % 2 == 0) {
                ano[i].n_dias = 30;
            } else {
                ano[i].n_dias = 31;
            }
        }
        nome_mes(&(ano[i]));
    }
    
    cout << endl << "Dia: ";
    cin >> dia;
    cout << "Mês: ";
    cin >> mes;

    if ((mes < 1 || mes > 12) || (dia > ano[mes-1].n_dias || dia < 1)) {
        cerr << "> Entrada invalida!!" << endl;
        return 1;
    } 

    // Dias transcorridos
    nc_dias = dia;
    for (int i = 0; i < mes - 1; i++) 
        nc_dias += ano[i].n_dias;
    
    cout << "> Dias transcorridos: " << nc_dias << endl
        << "> Dia informado ~ " << dia << " / " << "Mês informado ~ " << mes << endl
        << "> Dados (MÊS):" << endl
        << "\t~> Nome => " << ano[mes-1].nome << endl
        << "\t~> Abreviatura => " << ano[mes-1].abrev << endl
        << "\t~> Total de dias => " << ano[mes-1].n_dias << endl;
    return 0;
}
