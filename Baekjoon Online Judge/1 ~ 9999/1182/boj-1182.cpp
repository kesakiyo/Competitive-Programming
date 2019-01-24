#include <iostream>

using namespace std;

int n, target, A[21];

int func(int pos, int sum) {
	if (pos == n) {
		return sum == target ? 1 : 0;
	}
	return func(pos + 1, sum) + func(pos + 1, sum + A[pos]);
}

int main() {
	scanf("%d%d", &n, &target);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d", &A[i]);
	}

	int ans = func(0, 0);
	if (target == 0) {
		ans -= 1;
	}

	printf("%d\n", ans);
}