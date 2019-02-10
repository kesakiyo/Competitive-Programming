/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

const int MOD = 15746;
int n, cache[1000010];

int func(int idx) {
	if (idx == 0) {
		return 1;
	}

	int& ret = cache[idx];
	if (ret) {
		return ret;
	}

	ret = func(idx - 1) % MOD;
	if (idx >= 2) {
		ret = (ret + func(idx - 2)) % MOD;
	}
	
	return ret;
}

int main() {
	cin >> n;
	cout << func(n) << endl;
}