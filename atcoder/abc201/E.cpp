#include <bits/stdc++.h>
#include <atcoder/modint>

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

const int N = 1 << 18, B = 60;
vector<pair<int, ll>> g[N];
ll d[N];

void dfs(int u, int p) {
	for (auto [v, w] : g[u]) {
		if (v == p) continue;
		d[v] = w ^ d[u];
		dfs(v, u);
	}
}

const int M = 1e9 + 7;
using mint = atcoder::static_modint<M>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(e, 1, n) {
		int u, v; ll w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	dfs(0, -1);

	mint res = 0, cur = 1;
	rep(b, 0, B) {
		ll cnt = 0;
		rep(u, 0, n) cnt += d[u] >> b & 1;
		res += cur * cnt * (n - cnt);
		cur += cur;
	}

	cout << res.val() << '\n';
}