/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int tot = 0, A[9];
	for (int i = 0 ; i < 9 ; ++i) {
		cin >> A[i];
		tot += A[i];
	}

	sort(A, A + 9);
	for (int i = 0 ; i < 9 ; ++i) {
		for (int j = i + 1 ; j < 9 ; ++j) {
			if (tot - A[i] - A[j] == 100) {
				for (int k = 0 ; k < 9 ; ++k) {
					if (k != i && k != j) {
						cout << A[k] << endl;
					}
				}
				return 0;
			}
		}
	}
}