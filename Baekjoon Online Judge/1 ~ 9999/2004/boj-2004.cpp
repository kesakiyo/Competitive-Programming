/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>

using namespace std;

long long getFactors(long long num, long long factor) {
	long long ret = 0;
	for (long long i = factor ; i <= num ; i *= factor) {
		ret += num / i;
	}
	return ret;
}

int main() {
	long long n, r;
	cin >> n >> r;

	long long fact_2 = getFactors(n, 2);
	fact_2 -= getFactors(n - r, 2);
	fact_2 -= getFactors(r, 2);

	long long fact_5 = getFactors(n, 5);
	fact_5 -= getFactors(n - r, 5);
	fact_5 -= getFactors(r, 5);

	cout << (fact_2 < fact_5 ? fact_2 : fact_5) << endl;
}