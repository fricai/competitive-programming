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

int n, m;

vector<int> solve() {
	cin >> n >> m;

	vector<vector<int>> f(m), g(n);
	rep(i, 0, m) {
		int k; cin >> k;
		f[i].resize(k);
		for (auto &x : f[i]) cin >> x, g[--x].push_back(i);
	}

	vector<int> res(m, -1);
	
	int U = (m + 1) / 2, v = -1;
	rep(u, 0, n) if (sz(g[u]) > U) v = u;

	if (v < 0) {
		rep(i, 0, m) res[i] = f[i][0];
		return res;
	}
	
	int cnt = 0;
	for (auto i : g[v]) {
		if (sz(f[i]) > 1) continue;
		++cnt;
		res[i] = v;
	}

	if (cnt > U) return { };
	assert(sz(g[v]) > U);

	for (auto i : g[v]) {
		assert(!f[i].empty());
		if (sz(f[i]) == 1) continue;
		if (cnt == U) break;
		res[i] = v;
		++cnt;
	}
	
	rep(i, 0, m) {
		if (res[i] != -1) continue;
		for (auto x : f[i]) if (x != v) res[i] = x;
	}
	
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto res = solve();
		if (res.empty()) cout << "NO\n";
		else {
			cout << "YES\n";
			for (auto x : res) cout << x + 1 << ' ';
			cout << '\n';
		}
	}
}