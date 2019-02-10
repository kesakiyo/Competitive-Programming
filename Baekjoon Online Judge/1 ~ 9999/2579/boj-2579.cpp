/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

int n, cost[310], cache[310][2];

int func(int idx, int cont) {
	if (idx < 0) {
		return 0;
	}

	int& ret = cache[idx][cont];
	if (ret != -1) {
		return ret;
	}

	ret = cost[idx];
	if (cont < 1) {
		ret = max(ret, func(idx - 1, cont + 1) + cost[idx]);
	}
	ret = max(ret, func(idx - 2, 0) + cost[idx]);

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> cost[i];
	}

	memset(cache, -1, sizeof(cache));
	cout << func(n - 1, 0) << endl;
}