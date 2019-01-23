/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>

using namespace std;

int n;
string str[51];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> str[i];
    }

    int len = str[0].length();
    for (int i = 0 ; i < len ; ++i) {
        const char ch = str[0][i];
        bool flag = true;
        for (int j = 1 ; j < n ; ++j) {
            if (str[j][i] != ch) {
                flag = false;
                break;
            }
        }
        cout << (flag ? ch : '?');
    }
}
