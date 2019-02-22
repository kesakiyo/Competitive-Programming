/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;
long long cache[110][110][110];
int n, l, r;

long long func(int i, int j, int k) {
	if (j == 0 || k == 0) {
		return 0;
	} else if (i == n) {
		return (j == 1 && k == 1) ? 1 : 0;
	}

	long long& ret = cache[i][j][k];
	if (ret != -1) {
		return ret;
	}

	ret = (func(i + 1, j - 1, k) + func(i + 1, j, k - 1) + func(i + 1, j, k) * (i - 1)) % MOD;
	return ret;
}

int main() {
	cin >> n >> l >> r;
	memset(cache, -1, sizeof(cache));
	cout << func(1, l, r) << endl;

}