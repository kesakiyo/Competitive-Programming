/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	int ans = n + 1, sum = 0;
	queue<int> q;

	for (int i = 1 ; i <= n ; ++i) {
		int val;
		cin >> val;

		sum += val;
		q.push(val);

		while (!q.empty() && sum >= s) {
			if (ans > q.size()) {
				ans = q.size();
			}
			sum -= q.front();
			q.pop();
		}
	}

	cout << (ans == n + 1 ? 0 : ans) << endl;
}