/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAllCases(int pos, int sum, const vector<int>& vi, vector<int>& cases) {
	if (pos == vi.size()) {
		cases.push_back(sum);
		return;
	}
	getAllCases(pos + 1, sum, vi, cases);
	getAllCases(pos + 1, sum + vi[pos], vi, cases);
}

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> vi(n);
	for (int i = 0 ; i < n ; ++i) {
		cin >> vi[i];
	}

	vector<int> casesL, casesR;
	getAllCases(0, 0, vector<int>(vi.begin(), vi.begin() + n / 2), casesL);
	getAllCases(0, 0, vector<int>(vi.begin() + n / 2, vi.end()), casesR);

	sort(casesR.begin(), casesR.end());
	long long ans = 0;
	for (int val: casesL) {
		int target = s - val;
		ans += upper_bound(casesR.begin(), casesR.end(), target) - lower_bound(casesR.begin(), casesR.end(), target);
	}

	cout << (s == 0 ? ans - 1 : ans) << endl;
}