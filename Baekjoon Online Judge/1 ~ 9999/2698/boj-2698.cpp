/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

int t, n, k, cache[110][2][110];

int func(int idx, int cur, int sum) {
	if (sum < 0) {
		return 0;
	} else if (idx == 0) {
		return sum == 0 ? 1 : 0;
	}

	int& ret = cache[idx][cur][sum];
	if (ret != -1) {
		return ret;
	}

	ret = func(idx - 1, 1, sum - cur * 1) + func(idx - 1, 0, sum);

	return ret;
}

int main() {
	cin >> t;

	memset(cache, -1, sizeof(cache));
	while (t--) {
		cin >> n >> k;
		cout << func(n - 1, 0, k) + func(n - 1, 1, k) << endl;
	}
}