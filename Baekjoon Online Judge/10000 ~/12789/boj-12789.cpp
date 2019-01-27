/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, val, order = 1;
	stack<int> s;

	cin >> n;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> val;
		s.push(val);
		while (!s.empty() && s.top() == order) {
			s.pop();
			++order;
		}
	}

	cout << (order == n + 1 ? "Nice" : "Sad") << endl;
}