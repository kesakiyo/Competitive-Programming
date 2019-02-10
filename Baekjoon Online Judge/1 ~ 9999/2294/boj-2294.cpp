/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;
int n, k, coins[110], cache[10010];

int func(int money) {
	if (money == 0) {
		return 0;
	}

	int& ret = cache[money];
	if (ret != -1) {
		return ret;
	}

	ret = INF;
	for (int i = 0 ; i < n ; ++i) {
		const int coin = coins[i];
		if (money >= coin) {
			ret = min(ret, func(money - coin) + 1);
		}
	}

	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0 ; i < n ; ++i) {
		cin >> coins[i];
	}

	memset(cache, -1, sizeof(cache));
	int ans = func(k);
	cout << (ans == INF ? -1 : ans) << endl;
}