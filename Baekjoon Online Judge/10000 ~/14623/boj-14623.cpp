/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long btoll(const string& str) {
    long long ret = 0;
    for (int i = 0 ; i < str.length() ; ++i) {
        ret *= 2;
        ret += str[i] - '0';
    }
    return ret;
}

string lltob(long long n) {
    string ret = "";
    while (n) {
        ret += (n % 2) + '0';
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string str;

    cin >> str;
    long long a = btoll(str);

    cin >> str;
    long long b = btoll(str);

    string ans = lltob(a * b);
    cout << ans << endl;
}