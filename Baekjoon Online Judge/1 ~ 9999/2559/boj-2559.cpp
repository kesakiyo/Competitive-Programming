/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int n, k, A[100010];

int main() {
	cin >> n >> k;
	for (int i = 0 ; i < n ; ++i) {
		cin >> A[i];
	}

	int sum = 0;
	for (int i = 0 ; i < k ; ++i) {
		sum += A[i];
	}

	int ans = sum;
	for (int i = k ; i < n ; ++i) {
		sum += A[i];
		sum -= A[i - k];
		ans = sum > ans ? sum : ans;
	}

	cout << ans << endl;
}