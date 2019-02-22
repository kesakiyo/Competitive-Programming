/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int cnt[2];

int main() {
	cin >> str;

	++cnt[str[0] - '0'];
	for (int i = 1 ; i < str.length() ; ++i) {
		if (str[i - 1] != str[i]) {
			++cnt[str[i] - '0'];
		}
	}

	cout << min(cnt[0], cnt[1]) << endl;
}