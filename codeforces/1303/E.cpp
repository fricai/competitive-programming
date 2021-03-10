#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 9, A = 26;
int nxt[N][A], dp[N][N];

bool solve() {
	string s, t; cin >> s >> t;

	int n = sz(s), m = sz(t);
	
	rep(c, 0, A) nxt[n][c] = nxt[n + 1][c] = n;
	per(i, 0, n) {
		rep(c, 0, A) nxt[i][c] = nxt[i + 1][c];
		nxt[i][s[i] - 'a'] = i;
	}

	for (int x = 0, y = m; x < m; ++x, --y) {
		auto L = t.substr(0, x), R = t.substr(x, y);
		for (int i = 0; i <= x; ++i) {
			for (int j = 0; j <= y; ++j) {
				if (i || j) dp[i][j] = n + 1;
				if (i) ckmin(dp[i][j], nxt[dp[i - 1][j]][L[i - 1] - 'a'] + 1);
				if (j) ckmin(dp[i][j], nxt[dp[i][j - 1]][R[j - 1] - 'a'] + 1);
			}
		}
		if (dp[x][y] <= n) return 1;
	}

	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}