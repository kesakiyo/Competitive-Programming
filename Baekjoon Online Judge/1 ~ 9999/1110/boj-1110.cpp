/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int getNextNumber(int n) {
    int a = n % 10;
    int b = ((n / 10) + (n % 10)) % 10;
    return a * 10 + b;
}

int main() {
    int n, ans = 0;
    cin >> n;

    int cur = n;
    do {
        ++ans;
        cur = getNextNumber(cur);
    } while (cur != n);
    
    cout << ans << endl;
}