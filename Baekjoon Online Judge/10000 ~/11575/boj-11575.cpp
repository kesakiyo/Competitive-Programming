/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        string str;
        cin >> a >> b >> str;

        for (int i = 0 ; i < str.length() ; ++i) {
            const int x = str[i] - 'A';
            const char ch = (a * x + b) % 26 + 'A';
            cout << ch;
        }
        cout << endl;
    }
}
