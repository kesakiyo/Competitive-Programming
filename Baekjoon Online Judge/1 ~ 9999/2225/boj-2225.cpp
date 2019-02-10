/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9;
int n, k, cache[210][210];

int func(int num, int sel) {
	if (sel == 0) {
		return num == 0 ? 1 : 0;
	}

	int& ret = cache[num][sel];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i = 0 ; i <= n ; ++i) {
		if (num >= i) {
			ret = (ret + func(num - i, sel - 1)) % MOD;
		}
	}

	return ret;
}

int main() {
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));
	cout << func(n, k) << endl;
}