/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int main() {
    int n, m, A[310][310];
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++i) {
        for (int j = 1 ; j <= m ; ++j) {
            cin >> A[i][j];
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b, c, d, ans = 0;
        cin >> a >> b >> c >> d;

        for (int i = a ; i <= c ; ++i) {
            for (int j = b ; j <= d ; ++j) {
                ans += A[i][j];
            }
        }

        cout << ans << endl;
    }
}