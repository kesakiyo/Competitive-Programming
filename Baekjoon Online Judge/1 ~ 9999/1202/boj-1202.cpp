/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Gem {
	int weight, value;

	Gem(int _weight, int _value) {
		this->weight = _weight;
		this->value = _value;
	}

	bool operator < (const Gem& r) const {
		return this->value > r.value;
	}
};

int n, m, w, v;

int main() {
	cin >> n >> m;

	vector<Gem> gems;
	while (n--) {
		cin >> w >> v;
		gems.push_back(Gem(w, v));
	}
	sort(gems.begin(), gems.end());

	multiset<int> bags;
	while (m--) {
		cin >> v;
		bags.insert(v);
	}

	long long ans = 0;
	for(const auto& gem: gems) {
		auto it = bags.lower_bound(gem.weight);
		if (it != bags.end()) {
			ans += gem.value;
			bags.erase(it);
		}
	}

	cout << ans << endl;
}