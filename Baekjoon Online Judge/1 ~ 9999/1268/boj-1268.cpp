/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int main() {
	int n, A[1001][6];

	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < 5 ; ++j) {
			cin >> A[i][j];
		}
	}

	int mmax = -1, mmaxIdx = -1;
	for (int i = 0 ; i < n ; ++i) {
		int cnt = 0;
		for (int j = 0 ; j < n ; ++j) {
			if (i != j) {
				for (int k = 0 ; k < 5 ; ++k) {
					if (A[i][k] == A[j][k]) {
						++cnt;
						break;
					}
				}
			}
		}
		if (cnt > mmax) {
			mmax = cnt;
			mmaxIdx = i + 1;
		}
	}

	cout << mmaxIdx << endl;
}