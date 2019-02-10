/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

int n, A[110][110];
long long cache[110][110];

bool isPossible(int pos) {
	return 0 <= pos && pos < n;
}

long long func(int y, int x) {
	if (y == n - 1 && x == n - 1) {
		return 1;
	}

	long long& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	if (isPossible(y + A[y][x])) {
		ret = ret + func(y + A[y][x], x);
	}
	if (isPossible(x + A[y][x])) {
		ret = ret + func(y, x + A[y][x]);
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			cin >> A[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << func(0, 0) << endl;
}