/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int getTeam(int state, int num) {
	return (state & (1 << num)) ? 1 : 0;
}

int main() {
	int n, S[21][21];
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			cin >> S[i][j];
		}
	}


	int ans = 987654321;
	for (int state = 0 ; state < (1 << n) ; ++state) {
		if (__builtin_popcount(state) == (n >> 1)) {
			int score[2] = {0, 0};
			for (int i = 0 ; i < n ; ++i) {
				for (int j = 0 ; j < n ; ++j) {
					if (getTeam(state, i) == getTeam(state, j)) {
						score[getTeam(state, i)] += S[i][j];
					}
				}
			}
			ans = min(ans, abs(score[0] - score[1]));
		}
	}

	cout << ans << endl;
}