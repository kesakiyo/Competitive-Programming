/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, cost[10010], cache[10010][3];

int func(int idx, int cont) {
	if (idx == n) {
		return 0;
	}

	int& ret = cache[idx][cont];
	if (ret != -1) {
		return ret;
	}

	ret = func(idx + 1, 0);
	if (cont < 2) {
		ret = max(ret, func(idx + 1, cont + 1) + cost[idx]);
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> cost[i];
	}

	memset(cache, -1, sizeof(cache));
	cout << func(0, 0) << endl;
}