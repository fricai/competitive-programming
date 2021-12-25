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
	vector<int> p(n);
	for (auto &x : p)
		cin >> x, --x;

	int m; cin >> m;
	vector<int> a(m), b(m);
	vector<vector<int>> g(n), t(n);
	rep(e, 0, m) {
		cin >> a[e] >> b[e]; --a[e]; --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	vector<bool> vis(n);
	auto make_span = [&](const auto &dfs, int u) -> void {
		vis[u] = true;
		for (auto e : g[u]) {
			int v = a[e] ^ b[e] ^ u;
			if (vis[v]) continue;
			t[u].push_back(e);
			t[v].push_back(e);
			dfs(dfs, v);
		}
	};
	rep(u, 0, n) if (!vis[u]) make_span(make_span, u);

	vector<int> ans;
	auto do_swap = [&](int e) -> void {
		swap(p[a[e]], p[b[e]]);
		ans.emplace_back(e);
	};

	queue<int> q;

	vector<int> deg(n);
	rep(u, 0, n) deg[u] = sz(t[u]);
	rep(u, 0, n) if (deg[u] == 1) q.push(u);

	rep(u, 0, n) cerr << deg[u] << ' ';
	cerr << '\n';

	while (!q.empty()) {
		int i = q.front(); q.pop();

		vector<bool> vis(n);
		vector<int> path;
		auto get_path = [&](const auto &dfs, int u) -> bool {
			if (p[u] == i)
				return true;
			vis[u] = true;
			for (auto e : t[u]) {
				int v = a[e] ^ b[e] ^ u;
				if (!vis[v] && dfs(dfs, v)) {
					path.push_back(e);
					return true;
				}
			}
			return false;
		};

		if (!get_path(get_path, i)) {
			cout << "-1\n";
			return 0;
		}

		for (auto e : path) do_swap(e);
		assert(p[i] == i);
		for (auto e : t[i]) {
			int v = a[e] ^ b[e] ^ i;
			if (--deg[v] == 1)
				q.push(v);
		}
	}
	rep(i, 0, n) assert(p[i] == i);

	cout << sz(ans) << '\n';
	for (auto e : ans)
		cout << e + 1 << ' ';
	cout << '\n';
}
