/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Picture {
	int num, votes, order;
};

const int INF = 987654321;

int n, k, len;
Picture pictures[21];

void update(int num, int order) {
	for (int i = 0 ; i < len ; ++i) {
		if (pictures[i].num == num) {
			pictures[i].votes += 1;
			return;
		}
	}

	Picture p;
	p.num = num;
	p.order = order;
	p.votes = 1;

	if (len < n) {
		pictures[len] = p;
		len += 1;
		return;
	}

	int mmin = INF, mminIdx = -1;
	for (int i = 0 ; i < len ; ++i) {
		if (pictures[i].votes < mmin) {
			mmin = pictures[i].votes;
			mminIdx = i;
		} else if (
			pictures[i].votes == mmin 
			&& pictures[i].order < pictures[mminIdx].order
		) {
			mminIdx = i;
		}
	}

	pictures[mminIdx] = p;
}

int main() {
	cin >> n >> k;
	for (int i = 0 ; i < k ; ++i) {
		int num;
		cin >> num;
		update(num, i);
	}

	vector<int> ans;
	for (int i = 0 ; i < len ; ++i) {
		ans.push_back(pictures[i].num);
	}
	sort(ans.begin(), ans.end());

	for (int val: ans) {
		cout << val << " ";
	}
}