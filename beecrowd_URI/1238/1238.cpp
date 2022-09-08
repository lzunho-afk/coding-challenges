#include <iostream>

using namespace std;

int main(void) {
    int count, c1, c2;
    string s1, s2;

    cin >> count;
    while (count != 0) {
        cin >> s1 >> s2;

        c1 = c2 = 0;
        while (c1 != s1.length() && c2 != s2.length()) {
            cout << s1[c1] << s2[c2];
            c1++;
            c2++;
        }

        if (s1.length() > s2.length()) {
            cout << s1.substr(s2.length(), s1.length());
        } else {
            cout << s2.substr(s1.length(), s2.length());
        }

        cout << endl;
        count--;
    }
    return 0;
}
