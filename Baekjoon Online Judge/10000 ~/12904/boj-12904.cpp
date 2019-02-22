/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPossible(string src, string dest) {
	while (dest.size() > src.size()) {
		if (dest.back() == 'A') {
			dest.pop_back();	
		} else if (dest.back() == 'B') {
			dest.pop_back();
			reverse(dest.begin(), dest.end());
		}
	}
	return src == dest;
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << (isPossible(s, t) ? 1 : 0) << endl;
}