/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int main() {
	int sum = 0, mmin = 111, val;
	for (int i = 0 ; i < 7 ; ++i) {
		cin >> val;
		if (val % 2) {
			sum += val;
			mmin = val < mmin ? val : mmin;
		}
	}

	if (!sum) {
		cout << -1 << endl;
	} else {
		cout << sum << endl;
		cout << mmin << endl;
	}
}