/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, A[1010], cache[1010];

int func(int here) {
	int& ret = cache[here];
	if (ret) {
		return ret;
	}

	ret = 1;
	for (int there = here + 1 ; there < n ; ++there) {
		if (A[here] < A[there]) {
			ret = max(ret, func(there) + 1);
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> A[i];
	}

	int ans = 0;
	for (int i = 0 ; i < n ; ++i) {
		ans = max(ans, func(i));
	}

	cout << ans << endl;
}