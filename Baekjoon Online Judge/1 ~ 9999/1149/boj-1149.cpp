/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, cost[1010][3], dp[1010][3];

int func(int idx, int prevColor) {
	if (idx == n) {
		return 0;
	}

	int& ret = dp[idx][prevColor];
	if (ret) {
		return ret;
	}

	ret = INF;
	for (int curColor = 0 ; curColor < 3 ; ++curColor) {
		if (prevColor != curColor) {
			ret = min(ret, func(idx + 1, curColor) + cost[idx][curColor]);
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < 3 ; ++j) {
			cin >> cost[i][j];
		}
	}

	int ans = INF;
	for (int curColor = 0 ; curColor < 3 ; ++curColor) {
		ans = min(ans, func(1, curColor) + cost[0][curColor]);
	}

	cout << ans << endl;
}