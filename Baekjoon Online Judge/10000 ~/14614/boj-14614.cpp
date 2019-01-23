/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    string c;
    cin >> a >> b >> c;

    bool flag = (c[c.length() - 1] - '0') % 2;
    cout << (flag ? (a ^ b) : a) << endl;
}
