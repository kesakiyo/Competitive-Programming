/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int n;
long long cache[110][2];

long long func(int idx, int num) {
	if (idx == n) {
		return 1;
	}

	long long& ret = cache[idx][num];
	if (ret) {
		return ret;
	}

	if (num == 0) {
		ret = func(idx + 1, 1);
	}
	ret += func(idx + 1, 0);

	return ret;
}

int main() {
	cin >> n;
	cout << func(1, 1) << endl;
}