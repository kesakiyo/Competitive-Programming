/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, T[20], P[20], cache[20];

int func(int idx) {
	if (idx == n) {
		return 0;
	}

	int& ret = cache[idx];
	if (ret) {
		return ret;
	}

	ret = func(idx + 1);
	if (idx + T[idx] <= n) {
		ret = max(ret, func(idx + T[idx]) + P[idx]);
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> T[i] >> P[i];
	}

	cout << func(0) << endl;
}