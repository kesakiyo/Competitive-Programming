/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
const vector<vector<int>> switches = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

int func(int pos, int clocks[]) {
	if (pos == switches.size()) {
		for (int i = 0 ; i < 16 ; ++i) {
			if (clocks[i] != 0) {
				return INF;
			}
		}
		return 0;
	}

	const vector<int>& zwitch = switches[pos];

	int ret = INF;
	for (int i = 0 ; i < 4 ; ++i) {
		for (int idx: zwitch) {
			clocks[idx] = (clocks[idx] + i) % 4;
		}
		ret = min(ret, func(pos + 1, clocks) + i);
		for (int idx: zwitch) {
			clocks[idx] = (clocks[idx] - i + 4) % 4;
		}
	}

	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int* clocks  = new int[16];
		for (int i = 0 ; i < 16 ; ++i) {
			cin >> clocks[i];
			clocks[i] = (clocks[i] / 3) % 4;
		}

		int ans = func(0, clocks);
		cout << (ans == INF ? -1 : ans) << endl;
	}	
}