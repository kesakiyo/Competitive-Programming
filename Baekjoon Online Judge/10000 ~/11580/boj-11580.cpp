/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    set<pair<int ,int>> ans;
    ans.insert({ 0, 0 });
    int x = 0, y = 0;
    for (int i = 0 ; i < n ; ++i) {
        const char ch = str[i];
        if (ch == 'S') {
            y = y - 1;
        } else if (ch == 'N') {
            y = y + 1;
        } else if (ch == 'W') {
            x = x - 1;
        } else if (ch == 'E') {
            x = x + 1;
        }
        ans.insert({ x, y });
    }

    printf("%d\n", ans.size());
}
