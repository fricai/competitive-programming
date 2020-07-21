#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 12;
int p[N], cnt[N];
bool dp[N];

bool solve() {
	int n; cin >> n;
	rep(i, 0, 2 * n) cin >> p[i];

	int mx = 0, cmp = -1;
	rep(i, 0, 2 * n) {
		if (ckmax(mx, p[i])) cnt[++cmp] = 1;
		else ++cnt[cmp];
	}
	rep(x, 0, N) dp[x] = false;
	dp[0] = true;
	rep(k, 0, cmp)
		for (int x = N - 1; x >= 0; --x)
			if (dp[x]) dp[x + cnt[k]] = true;
	return dp[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}