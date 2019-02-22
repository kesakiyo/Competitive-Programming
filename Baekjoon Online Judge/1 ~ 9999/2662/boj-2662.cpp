/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k, A[21][310], cache[21][310];

int func(int idx, int money) {
	if (idx == m) {
		return 0;
	}

	int& ret = cache[idx][money];
	if (ret != -1) {
		return ret;
	}

	for (int i = 0 ; i <= money ; ++i) {
		ret = max(ret, func(idx + 1, money - i) + A[idx][i]);
	}

	return ret;
}

void backTrack(int idx, int money) {
	if (idx == m) {
		return;
	}

	for (int i = 0 ; i <= money ; ++i) {
		if (func(idx, money) == func(idx + 1, money - i) + A[idx][i]) {
			cout << i << " ";
			backTrack(idx + 1, money - i);
			break;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> k;
		for (int j = 0 ; j < m ; ++j) {
			cin >> A[j][k];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << func(0, n) << endl;
	backTrack(0, n);
}