/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int INF = 987654321;
int n, A[20010];

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> A[i];
	}

	int mmin = INF, mminIdx = -1;
	for (int i = 0 ; i < n ; ++i) {
		int sum = 0;
		for (int j = 0 ; j < n ; ++j) {
			sum += abs(A[i] - A[j]);
		}
		if (sum < mmin) {
			mmin = sum;
			mminIdx = i;
		} else if (sum == mmin && A[i] < A[mminIdx]) {
			mminIdx = i;
		}
	}

	cout << A[mminIdx] << endl;
}