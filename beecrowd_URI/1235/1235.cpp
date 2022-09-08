#include <iostream>

using namespace std;

int main(void) {
    int c;
    string phrase, s1, s2;

    cin >> c;
    while (c != 0) {
        fflush(stdin);
        getline(cin, phrase);

        s1 = phrase.substr(0, phrase.length()/2);
        s2 = phrase.substr(phrase.length()/2, phrase.length()/2);

        for (int i = s1.length() - 1; i >= 0; i--) {
            cout << s1[i];
        }
        for (int i = s2.length() - 1; i >= 0; i--) {
            cout << s2[i];
        }
        cout << endl;
        c--;
    }
    return 0;
}
