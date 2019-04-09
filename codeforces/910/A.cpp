#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d; cin >> n >> d;
	string S; cin >> S;
	vector<bool> x(n); vector<int> dp(n, n);
	REP(i, 0, n) {
		x[i] = S[i] - '0';
	}
	dp[0] = 0;
	REP(i, 1, n) {
		if (x[i]) {
			bool flag = true;
			REP(j, 1, d + 1) {
				if (i - j >= 0) {
					if (x[i - j]) {
						dp[i] = min(dp[i], dp[i - j] + 1);
						flag = false;
					}
				}
			}
			if (flag) {
				dp[n - 1] = -1;
				break;
			}
		}
	}
	cout << dp[n - 1];
}
