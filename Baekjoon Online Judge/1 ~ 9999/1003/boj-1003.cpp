/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int cache0[41], cache1[41];

int func(int n, int base, int cache[]) {
	if (n <= 1) {
		return n == base ? 1 : 0;
	}

	int& ret = cache[n];
	if (ret) {
		return ret;
	}

	ret = func(n - 1, base, cache) + func(n - 2, base, cache);
	return ret;
}

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << func(n, 0, cache0) << " " << func(n, 1, cache1) << endl;
	}
}