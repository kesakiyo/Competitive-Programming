/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int getGcd(int a, int b) {
    if (!b) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        const int gcd = getGcd(a, b);
        cout << (a * b) / gcd << endl;
    }
}
