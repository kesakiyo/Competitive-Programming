/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt[26];
    fill(cnt, cnt + 26, 0);

    for (int i = 0 ; i < str.length() ; ++i) {
        char ch = str[i];
        if ('a' <= ch && ch <= 'z') {
            ch -= ('a' - 'A');
        }
        ++cnt[ch - 'A'];
    }

    int maxIdx = 0;
    bool isMultiple = false;
    for (int i = 1 ; i < 26 ; ++i) {
        if (cnt[i] > cnt[maxIdx]) {
            maxIdx = i;
            isMultiple = false;
        } else if (cnt[i] == cnt[maxIdx]) {
            isMultiple = true;
        }
    }

    cout << (isMultiple ? '?' : (char)(maxIdx + 'A')) << endl;
}
