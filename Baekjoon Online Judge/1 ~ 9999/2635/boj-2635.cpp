/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> calc(vector<int> vi) {
	while (1) {
		int len = vi.size();
		int next = vi[len - 2] - vi[len - 1];
		if (next < 0) {
			return vi;
		}
		vi.push_back(next);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> ans;
	for (int i = 1 ; i <= n ; ++i) {
		vector<int> vi = calc({ n, i });
		if (vi.size() > ans.size()) {
			ans = vi;
		}
	}

	cout << ans.size() << endl;
	for (int val: ans) {
		cout << val << " ";
	}
}