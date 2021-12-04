#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int inf = 50000;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int x, y; cin >> x >> y;
	vector<pair<int, int>> t(n);
	for (auto &[a, b] : t) cin >> a >> b;

	vector dp(x + 1, vector(y + 1, inf));

	dp[0][0] = 0;
	for (auto [a, b] : t) {
		for (int i = x; i >= 0; --i) {
			for (int j = y; j >= 0; --j) {
				if (!i && !j)
					continue;
				uin(dp[i][j], dp[max(0, i - a)][max(0, j - b)] + 1);
			}
		}
	}
	cout << (dp[x][y] < inf ? dp[x][y] : -1) << '\n';
}
