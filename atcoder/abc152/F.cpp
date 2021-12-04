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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> g(n);
	vector<int> a(n - 1), b(n - 1);
	rep(e, 0, n - 1) {
		cin >> a[e] >> b[e]; --a[e]; --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	int m; cin >> m;
	vector<ll> paths(m);
	for (auto &z : paths) {
		int x, y; cin >> x >> y; --x; --y;
		auto dfs = [&](const auto &self, int u, int p) -> bool {
			if (u == y)
				return true;
			for (auto e : g[u]) {
				if (e != p && self(self, a[e] ^ b[e] ^ u, e)) {
					z |= 1ll << e;
					return true;
				}
			}
			return false;
		};
		dfs(dfs, x, -1);
	}

	ll ans = 0;
	rep(S, 0, 1 << m) {
		ll p = 0;
		rep(i, 0, m) if (S >> i & 1) p |= paths[i];
		ll r = __builtin_popcountll(p);
		if (__builtin_popcount(S) & 1)
			ans -= 1ll << (n - 1 - r);
		else
			ans += 1ll << (n - 1 - r);
	}
	cout << ans << '\n';
}
