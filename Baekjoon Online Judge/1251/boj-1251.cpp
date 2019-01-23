/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    string ans = "";
    for (int i = 1 ; i < str.length() ; ++i) {
        for (int j = i + 1 ; j < str.length() ; ++j) {
            string temp = str;
            reverse(temp.begin(), temp.begin() + i);
            reverse(temp.begin() + i, temp.begin() + j);
            reverse(temp.begin() + j, temp.end());

            if (ans.empty() || temp < ans) {
                ans = temp;
            }
        }
    }

    cout << ans << endl;
}