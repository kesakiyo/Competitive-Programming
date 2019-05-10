/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, m, u, v, w, A[310][310];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 1 ; j <= n ; ++j) {
			A[i][j] = i == j ? 0 : INF;
		}
	}

	while (m--) {
		cin >> u >> v >> w;
		if (w == 1) {
			A[u][v] = A[v][u] = 0;
		} else {
			A[u][v] = 0;
			A[v][u] = 1;
		}
	}

	for (int k = 1 ; k <= n ; ++k) {
		for (int i = 1 ; i <= n ; ++i) {
			for (int j = 1 ; j <= n ; ++j) {
				if (A[i][k] != INF && A[k][j] != INF) {
					A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				}
			}
		}
	}

	cin >> m;
	while (m--) {
		cin >> u >> v;
		cout << A[u][v] << '\n';
	}
}