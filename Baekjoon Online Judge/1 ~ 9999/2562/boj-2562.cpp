/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

int main() {
	int mmax = 0, mmaxIdx = 0, val;
	for (int i = 1 ; i <= 9 ; ++i) {
		cin >> val;
		if (val > mmax) {
			mmax = val;
			mmaxIdx = i;
		}
	}

	cout << mmax << endl;
	cout << mmaxIdx << endl;
}