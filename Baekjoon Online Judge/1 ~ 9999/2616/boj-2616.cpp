/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, A[50010], psum[50010], cache[50010][3];

int func(int idx, int num) {
	if (idx == n + 1 || num == 3) {
		return 0;
	}

	int& ret = cache[idx][num];
	if (ret != -1) {
		return ret;
	}

	ret = max(
		func(idx + 1, num),
		func(min(idx + k, n + 1), num + 1) + psum[min(idx + k, n + 1) - 1] - psum[idx - 1]
	);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> A[i];
		psum[i] = psum[i - 1] + A[i];
	}
	cin >> k;

	memset(cache, -1, sizeof(cache));
	cout << func(1, 0) << endl;
}