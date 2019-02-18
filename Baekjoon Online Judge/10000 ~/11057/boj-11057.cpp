/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10007;
int n, cache[1010][10];

int func(int idx, int cur) {
	if (idx == n - 1) {
		return 1;
	}

	int& ret = cache[idx][cur];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int next = cur ; next < 10 ; ++next) {
		ret = (ret + func(idx + 1, next)) % MOD;
	}

	return ret;
}

int main() {
	cin >> n;

	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 0 ; i < 10 ; ++i) {
		ans = (ans + func(0, i)) % MOD;
	}

	cout << ans << endl;
}