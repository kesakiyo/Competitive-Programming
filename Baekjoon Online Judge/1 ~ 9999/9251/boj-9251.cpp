/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string A, B;
int cache[1010][1010];

int func(int x, int y) {
	if (x == A.length() || y == B.length()) {
		return 0;
	}

	int& ret = cache[x][y];
	if (ret != -1) {
		return ret;
	}

	ret = max(func(x + 1, y), func(x, y + 1));
	if (A[x] == B[y]) {
		ret = max(ret, func(x + 1, y + 1) + 1);
	}

	return ret;
}

int main() {
	cin >> A >> B;

	memset(cache, -1, sizeof(cache));
	cout << func(0, 0) << endl;
}