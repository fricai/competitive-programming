#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17;
int col[N], f[N];
int solve() {
	int m, n; cin >> n >> m;

	int ans = m;

	fill_n(f + 1, n, 0);
	rep(i, 0, m) {
		int x; cin >> x >> f[x];
		ans -= f[x] == x;
	}

	fill_n(col + 1, n, 0);

	for (int u = 1; u <= n; ++u) {
		if (col[u]) continue;
		int v;
		for (v = u; v && col[v] == 0; v = f[v]) col[v] = 1;
		if (v && col[v] == 1 && f[v] != v) ++ans;
		for (v = u; v && col[v] == 1; v = f[v]) col[v] = 2;
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}