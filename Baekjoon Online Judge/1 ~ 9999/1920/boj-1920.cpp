/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> vi(n);
	for (int i = 0 ; i < n ; ++i) {
		cin >> vi[i];
	}

	sort(vi.begin(), vi.end());
	int m, val;
	cin >> m;
	while (m--) {
		cin >> val;
		if (binary_search(vi.begin(), vi.end(), val)) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}