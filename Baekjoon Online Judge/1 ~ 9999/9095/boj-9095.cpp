/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

int cache[20];

int func(int num) {
	if (num == 0) {
		return 1;
	}

	int& ret = cache[num];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i = 1 ; i <= 3 ; ++i) {
		if (num >= i) {
			ret += func(num - i);
		}
	}

	return ret;
}

int main() {
	int t, n;
	cin >> t;

	memset(cache, -1, sizeof(cache));
	while (t--) {
		cin >> n;
		cout << func(n) << endl;
	}
}