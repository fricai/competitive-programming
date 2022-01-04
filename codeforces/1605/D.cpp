#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int B = 18;

int msb(int x) { return 31 - __builtin_clz(x); }

vector<int> solve() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<short> col(n, -1);
	auto init = [&](const auto &dfs, int u) -> void {
		for (auto v : g[u]) {
			if (~col[v]) continue;
			col[v] = !col[u];
			dfs(dfs, v);
		}
	};
	col[0] = 0;
	init(init, 0);

	vector<int> p(n);
	array<vector<int>, 2> grp;
	rep(i, 0, n) grp[col[i]].push_back(i);
	per(b, 0, B) {
		int c = sz(grp[0]) < sz(grp[1]) ? 1 : 0;
		for (int i = 1; i <= n; ++i) {
			if (msb(i) != b)
				continue;
			p[grp[c].back()] = i;
			grp[c].pop_back();
		}
	}
	return p;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		for (auto x : solve())
			cout << x << ' ';
		cout << '\n';
	}
}
