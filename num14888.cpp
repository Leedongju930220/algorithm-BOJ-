#include <iostream>
using namespace std;

int n, num[101], cal[4];
long long Max = -1000000000, Min = 1000000000;

void ret(int a, int b, int c, int d, int depth, long long sum) {
	if (depth == n - 1) {
		if (Max < sum) { Max = sum; }
		if (Min > sum) { Min = sum; }
		return;
	}
	if (a > 0) { ret(a - 1, b, c, d, depth + 1, sum + num[depth + 1]); }
	if (b > 0) { ret(a, b - 1, c, d, depth + 1, sum - num[depth + 1]); }
	if (c > 0) { ret(a, b, c - 1, d, depth + 1, sum * num[depth + 1]); }
	if (d>0) { ret(a, b, c, d - 1, depth + 1, sum / num[depth + 1]); }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> num[i]; }
	for (int i = 0; i < 4; i++) { cin >> cal[i]; }
	ret(cal[0], cal[1], cal[2], cal[3], 0, num[0]);
	cout << Max << '\n' << Min << '\n';
	return 0;
}
