/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <stdio.h>

using namespace std;

void func(int pos, int a, int b, int c) {
    if (pos == 0) {
        return;
    }
    func(pos - 1, a, c, b);
    printf("%d %d\n", a, c);
    func(pos - 1, b, a, c);
}

int main() {
    int n;
    scanf("%d", &n);

    int cnt = 1;
    for (int i = 1 ; i <= n ; ++i) {
        cnt *= 2;
    }

    printf("%d\n", cnt - 1);
    func(n, 1, 2, 3);
}
