/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(const string& str) {
	stack<char> s;
	for (int i = 0 ; i < str.size() ; ++i) {
		const char ch = str[i];
		if (ch == '(') {
			s.push(ch);
		} else {
			if (s.empty() || s.top() != '(') {
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cout << (isValid(str) ? "YES" : "NO") << endl;
	}
}