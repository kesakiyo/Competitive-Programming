/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (long long i = 2 ; i * i <= (long long)n ; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int len, int num) {
    if (len == 0) {
        cout << num << endl;
        return;
    }
    for (int i = 0 ; i < 10 ; ++i) {
        int next = num * 10 + i;
        if (isPrime(next)) {
            dfs(len - 1, next);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1 ; i < 10 ; ++i) {
        if (isPrime(i)) {
            dfs(n - 1, i);
        }
    }
}
