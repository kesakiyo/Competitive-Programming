/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <queue>

using namespace std;

int n, k, A[300010];
priority_queue<int> pq;

int main() {
	cin >> n >> k;
	for (int i = 0 ; i < n ; ++i) {
		cin >> A[i];
	}

	long long ans = 0;
	for (int i = 1 ; i < n ; ++i) {
		ans += A[i] - A[i - 1];
		pq.push(A[i] - A[i - 1]);
	}

	while (--k) {
		ans -= pq.top();
		pq.pop();
	}

	cout << ans << endl;
}