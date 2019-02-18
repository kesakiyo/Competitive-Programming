/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9;
int n, cache[101][10][1 << 10];

int func(int idx, int cur, int state) {
	if (idx == n - 1) {
		return state == (1 << 10) - 1 ? 1 : 0;
	}

	int& ret = cache[idx][cur][state];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	if (cur > 0) {
		int nextState = state | (1 << (cur - 1));
		ret = (ret + func(idx + 1, cur - 1, nextState)) % MOD;
	}
	if (cur < 9) {
		int nextState = state | (1 << (cur + 1));
		ret = (ret + func(idx + 1, cur + 1, nextState)) % MOD;
	}

	return ret;
}

int main() {
	cin >> n;

	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 1 ; i < 10 ; ++i) {
		ans = (ans + func(0, i, 1 << i)) % MOD;
	}

	cout << ans << endl;
}