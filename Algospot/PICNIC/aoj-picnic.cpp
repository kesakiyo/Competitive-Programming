/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

int t, n, m;
bool isFriend[11][11];

int func(int pos, bool isPaired[]) {
	if (pos == n) {
		for (int i = 0 ; i < n ; ++i) {
			if (!isPaired[i]) {
				return 0;
			}
		}
		return 1;
	} else if (isPaired[pos]) {
		return func(pos + 1, isPaired);
	}

	int ret = 0;
	for (int i = pos + 1 ; i < n ; ++i) {
		if (isFriend[pos][i] && !isPaired[i]) {
			isPaired[pos] = isPaired[i] = true;
			ret += func(pos + 1, isPaired);
			isPaired[pos] = isPaired[i] = false;
		}
	}

	return ret;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(isFriend, false, sizeof(isFriend));
		while (m--) {
			int i, j;
			cin >> i >> j;
			isFriend[i][j] = isFriend[j][i] = true;
		}

		bool* isPaired = new bool[n];
		memset(isPaired, false, sizeof(isPaired[0]) * n);

		int ans = func(0, isPaired);
		cout << ans << endl;
	}
}