/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>

using namespace std;

int t, n, m;
string str[20];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0 ; i < n ; ++i) {
			cin >> str[i];
		}
		for (int i = n - 1 ; i >= 0 ; --i) {
			cout << str[i] << endl;
		}
	}
}