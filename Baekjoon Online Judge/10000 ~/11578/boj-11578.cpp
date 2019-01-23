/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int func(int pos, int left, int S[]) {
    if (pos == -1) {
        return left != 0 ? INF : 0;
    }
    return min(
        func(pos - 1, left & (~S[pos]), S) + 1,
        func(pos - 1, left, S)
    );
}

int main() {
    int n, m, S[20];
    cin >> n >> m;

    fill(S, S + 20, 0);
    for (int i = 0 ; i < m ; ++i) {
        int o, p;
        cin >> o;
        while (o--) {
            cin >> p;
            S[i] |= (1 << (p - 1));
        }
    }

    int ans = func(m - 1, (1 << n) - 1, S);
    cout << (ans == INF ? -1 : ans) << endl;
}
