#include <iostream>

using namespace std;

bool ver_input(string s1, string s2);
string iq_ch(string s1, string s2);
string just_ch(string s1, string s2);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    string s1, s2;

    cout << "Primeira string: ";
    cin >> s1;
    cin.ignore();
    cout << "Segunda string: ";
    cin >> s2;
    cin.ignore();

    if (ver_input(s1, s2)) {
        cout << "Caracteres nas duas strings: " << iq_ch(s1, s2) << endl
            << "Caracteres somentes na string 1: " << just_ch(s1, s2) << endl
            << "Caracteres somentes na string 2: " << just_ch(s2, s1) << endl;
    }

    return 0;
}

string iq_ch(string s1, string s2) {
    string out;
    string out_t;

    bool aux = true;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                for (int h = 0; h < out.length(); h++) {
                    if (out[h] == s1[i]) {
                        aux = false;
                    }
                }
                if (aux) {
                    out += s1[i];
                }
            }
        }
    }

    for (int i = 0; i < out.length(); i++) {
        out_t += out[i];
        if (!(i + 1 == out.length())) {
            out_t += ", ";
        }
    }

    return out_t;
}

string just_ch(string s1, string s2) {
    string out;
    string out_t;
    int dif_c;
    bool aux = true;

    dif_c = 0;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] != s2[j]) {
                dif_c++;
            } else {
                break;
            }
        }
        if (dif_c == s2.length()) {
            for (int h = 0; h < out.length(); h++) {
                if (out[h] == s1[i]) {
                    aux = false;
                }
            }
            if (aux) {
                out += s1[i];
            }
        }
        dif_c = 0;
        aux = true;
    }

    for (int i = 0; i < out.length(); i++) {
        out_t += out[i];
        if (!(i + 1 == out.length())) {
            out_t += ", ";
        }
    }
    return out_t;
}

bool ver_input(string s1, string s2) {
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (!(isalnum(s1[i]) && isalnum(s2[i]))) {
                cerr << "> Err.: Presença de caracteres especiais." << endl;
                return false;
            }
        }
    } else {
        cerr << "> Err.: As strings são diferentes." << endl;
        return false;
    }
    return true;
}
