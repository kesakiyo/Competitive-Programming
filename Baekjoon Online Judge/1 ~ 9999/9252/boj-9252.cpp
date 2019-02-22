/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string a, b;
int cache[1010][1010];

int func(int i, int j) {
	if (i == a.length() || j == b.length()) {
		return 0;
	}

	int& ret = cache[i][j];
	if (ret != -1) {
		return ret;
	}

	ret = max(func(i + 1, j), func(i, j + 1));
	if (a[i] == b[j]) {
		ret = max(ret, func(i + 1, j + 1) + 1);
	}

	return ret;
}

void backTrack(int i, int j) {
	if (i == a.length() || j == b.length()) {
		return;
	}
	if (func(i, j) == func(i + 1, j)) {
		backTrack(i + 1, j);
	} else if (func(i, j) == func(i, j + 1)) {
		backTrack(i, j + 1);
	} else if (a[i] == b[j] && func(i, j) == func(i + 1, j + 1) + 1) {
		cout << a[i];
		backTrack(i + 1, j + 1);
	}
}

int main() {
	cin >> a >> b;

	memset(cache, -1, sizeof(cache));
	cout << func(0, 0) << endl;
	backTrack(0, 0);
}