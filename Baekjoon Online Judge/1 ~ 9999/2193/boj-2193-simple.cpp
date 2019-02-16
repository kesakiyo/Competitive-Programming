/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int n;
long long cache[110];

long long func(int idx) {
	if (idx >= n) {
		return idx == n ? 1 : 0;
	}

	long long& ret = cache[idx];
	if (ret) {
		return ret;
	}

	ret = func(idx + 2) + func(idx + 1);
	return ret;
}

int main() {
	cin >> n;
	cout << func(1) << endl;
}