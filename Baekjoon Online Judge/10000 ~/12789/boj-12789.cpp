/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <stack>

using namespace std;

int n, v;
stack<int> s;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;

	int cur = 1;
	while (n--) {
		cin >> v;
		s.push(v);

		while (!s.empty() && s.top() == cur) {
			++cur;
			s.pop();
		}
	}

	cout << (s.empty() ? "Nice" : "Sad") << endl;
}