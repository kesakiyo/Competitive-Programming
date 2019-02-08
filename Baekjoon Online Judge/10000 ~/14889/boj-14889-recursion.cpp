/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

const int INF = 987654321;
int n, S[21][21];

int calc(int team[]) {
	int cnt[2] = {0, 0};
	for (int i = 0 ; i < n ; ++i) {
		cnt[team[i]] += 1;
	}

	if (cnt[0] != cnt[1]) {
		return INF;
	}

	int score[2] = {0, 0};
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i != j && team[i] == team[j]) {
				score[team[i]] += S[i][j];
			}
		}
	}

	return abs(score[0] - score[1]);
}

int func(int num, int team[]) {
	if (num == n) {
		return calc(team);
	}

	int ret = INF;

	team[num] = 0;
	ret = min(ret, func(num + 1, team));
	team[num] = -1;

	team[num] = 1;
	ret = min(ret, func(num + 1, team));
	team[num] = -1;

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			cin >> S[i][j];
		}
	}

	int* team = new int[n];
	fill(team, team + n, -1);

	int ans = func(0, team);
	cout << ans << endl;
}