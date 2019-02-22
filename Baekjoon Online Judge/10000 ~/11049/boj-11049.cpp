/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<unsigned int>().max();
int n, R[510], C[510];
unsigned int cache[510][510];

unsigned int func(int lo, int hi) {
	if (lo >= hi) {
		return 0;
	}

	unsigned int& ret = cache[lo][hi];
	if (ret != INF) {
		return ret;
	}

	for (int mid = lo ; mid < hi ; ++mid) {
		int cur = R[lo] * C[mid] * C[hi];
		ret = min(ret, func(lo, mid) + func(mid + 1, hi) + cur);
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> R[i] >> C[i];
	}

	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			cache[i][j] = INF; 
		}
	}

	cout << func(0, n - 1) << endl;
}