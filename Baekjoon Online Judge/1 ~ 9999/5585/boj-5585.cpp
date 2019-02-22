/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

const int N = 6;
const int coins[] = { 500, 100, 50, 10, 5, 1 };
int n, ans;

int main() {
	cin >> n;
	n = 1000 - n;
	for (int i = 0 ; i < N ; ++i) {
		const int coin = coins[i];
		ans += n / coin;
		n %= coin;
	}
	cout << ans << endl;
}