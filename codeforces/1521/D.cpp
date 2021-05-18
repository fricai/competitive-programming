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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
vector<int> g[N];

vector<tuple<int, int, int, int>> op;

void do_op(int u1, int v1, int u2, int v2) {
	op.emplace_back(u1 + 1, v1 + 1, u2 + 1, v2 + 1);
}

pair<int, int> dfs(int u) {
	int L = u, R = u;

	vector<tuple<int, int, int>> tr;
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));

		auto [l, r] = dfs(v);
		
		if (R == u && l == v)
			R = r;
		else if (L == u && l == v)
			L = r;
		else tr.emplace_back(v, l, r);
	}
	
	for (auto [v, l, r] : tr) {
		do_op(u, v, R, l);
		R = r;
	}
	
	return {L, R};
}

void solve() {
	int n; cin >> n;

	rep(u, 0, n) g[u].clear();
	op.clear();

	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);

	cout << sz(op) << '\n';
	for (auto [a, b, c, d] : op)
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}