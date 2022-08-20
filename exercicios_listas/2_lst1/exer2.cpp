#include <iostream>
#include <vector>

using namespace std;

typedef struct product {
    string name;
    int code;
    int count;
    double val;
} Product;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    cout.precision(2);

    vector< Product > items;
    Product item;
    double val;
    bool state = true;
    int es, code, count;

    while (state) {
        cout << "Informe o código do produto: ";
        cin >> code;

        cout << "Quantidade: ";
        cin >> count;

        switch (code) {
            case 10:
                item.name = "Cachorro quente";
                val = 15.00;
                break;
            case 11:
                item.name = "Bauru simples";
                val = 18.50;
                break;
            case 12:
                item.name = "Bauru com ovo";
                val = 22.00;
                break;
            case 13:
                item.name = "Hambúrger";
                val = 26.00;
                break;
            case 14:
                item.name = "Cheeseburguer";
                val = 22.00;
                break;
            case 15:
                item.name = "Torrada";
                val = 10.00;
                break;
            case 1:
                item.name = "Refrigerante";
                val = 7.50;
                break;
            case 2:
                item.name = "Suco Natural";
                val = 10.00;
                break;
            case 3:
                item.name = "Água";
                val = 5.00;
                break;
            default:
                cerr << "Código invalido!" << endl;
                val = -1.00;
                break;
        }
        if (val == -1.00)
            continue;
        item.code = code;
        item.count = count;
        item.val = val * item.count;
        items.push_back(item);

        while (state) {
            cout << "1 - Incluir mais um item" << endl
                << "2 - Encerrar o pedido" << endl
                << ":";
            cin >> es;

            switch(es) {
                case 1:
                    while (true) {
                        cout << "Informe o código do produto: ";
                        cin >> code;

                        cout << "Quantidade: ";
                        cin >> count;

                        switch (code) {
                            case 10:
                                item.name = "Cachorro quente";
                                val = 15.00;
                                break;
                            case 11:
                                item.name = "Bauru simples";
                                val = 18.50;
                                break;
                            case 12:
                                item.name = "Bauru com ovo";
                                val = 22.00;
                                break;
                            case 13:
                                item.name = "Hambúrger";
                                val = 26.00;
                                break;
                            case 14:
                                item.name = "Cheeseburguer";
                                val = 22.00;
                                break;
                            case 15:
                                item.name = "Torrada";
                                val = 10.00;
                                break;
                            case 1:
                                item.name = "Refrigerante";
                                val = 7.50;
                                break;
                            case 2:
                                item.name = "Suco Natural";
                                val = 10.00;
                                break;
                            case 3:
                                item.name = "Água";
                                val = 5.00;
                                break;
                            default:
                                cerr << "Código invalido!" << endl;
                                val = -1.00;
                        }
                        if (val == -1.00)
                            continue;
                        item.code = code;
                        item.count = count;
                        item.val = val * item.count;
                        items.push_back(item);
                        break;
                    }
                    break;
                case 2:
                    state = true;
                    val = 0.00;

                    cout.width(24);
                    cout << left << "Descrição";
                    cout.width(3);
                    cout << right << "QTD";
                    cout.width(24);
                    cout << right << "Valor do item" << endl;
                    cout << fixed;
                    for (int i = 0; i < items.size(); i++) {
                        cout.width(24);
                        cout << left << items[i].name;
                        cout.width(3);
                        cout << right << items[i].count;
                        cout.width(24);
                        cout << right << items[i].val << endl;
                        val += items[i].val;
                    }
                    cout.fill('.');
                    cout.width(51);
                    cout << left << "Total do pedido:"
                        << right << val << endl;
                    return 0;
                default:
                    cerr << "Escolha invalida!" << endl;
                    break;
            }
        }
    }
    return 0;
}
