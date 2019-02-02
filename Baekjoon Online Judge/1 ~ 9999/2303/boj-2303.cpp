/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getScore(const vector<int>& vi) {
	int mmax = -1;
	for (int i = 0 ; i < 5 ; ++i) {
		for (int j = i + 1 ; j < 5 ; ++j) {
			for (int k = j + 1 ; k < 5 ; ++k) {
				int sum = vi[i] + vi[j] + vi[k];
				mmax = max(mmax, sum % 10);
			}
		}
	}
	return mmax;
}

int main() {
	int n;
	cin >> n;

	int mmax = -1, mmaxIdx = -1;
	for (int i = 1 ; i <= n ; ++i) {
		vector<int> vi(5);
		for (int j = 0 ; j < 5 ; ++j) {
			cin >> vi[j];
		}

		int score = getScore(vi);
		if (score >= mmax) {
			mmax = score;
			mmaxIdx = i;
		}
	}

	cout << mmaxIdx << endl;
}