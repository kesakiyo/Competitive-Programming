/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

int t, n;
long long A[510], psum[510], cache[510][510];

long long func(int lo, int hi) {
	if (lo == hi) {
		return 0;
	}

	long long& ret = cache[lo][hi];
	if (ret != -1) {
		return ret;
	}

	ret = numeric_limits<long long>().max();
	for (int mid = lo ; mid < hi ; ++mid) {
		ret = min(ret, func(lo, mid) + func(mid + 1, hi) + psum[hi] - psum[lo - 1]);
	}
	return ret;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1 ; i <= n ; ++i) {
			cin >> A[i];
			psum[i] = psum[i - 1] + A[i];
		}
		memset(cache, -1, sizeof(cache));
		cout << func(1, n) << endl;
	}
}