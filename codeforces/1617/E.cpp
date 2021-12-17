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

int parent(int x) {
	if ((x & (x - 1)) == 0)
		return 0;
	int j = 32 - __builtin_clz(x);
	return (1 << j) - x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<int> cmp;
	cmp.push_back(0);
	for (auto x : a) {
		while (x != 0) {
			cmp.push_back(x);
			x = parent(x);
		}
	}
	sort(all(cmp));
	cmp.erase(unique(all(cmp)), end(cmp));

	vector<vector<int>> g(sz(cmp));
	vector<int> marked;

	for (auto x : a) {
		marked.push_back(lower_bound(all(cmp), x) - begin(cmp));
		while (x != 0) {
			int p = parent(x);

			int u = lower_bound(all(cmp), p) - begin(cmp);
			int v = lower_bound(all(cmp), x) - begin(cmp);

			g[u].push_back(v);
			g[v].push_back(u);

			x = p;
		}
	}

	for (auto &v : g) {
		sort(all(v));
		v.erase(unique(all(v)), end(v));
	}

	auto furthest = [&](int x) {
		vector<int> d(sz(g));
		auto dfs = [&](const auto &self, int u, int p) -> void {
			for (auto v : g[u]) {
				if (v != p) {
					d[v] = d[u] + 1;
					self(self, v, u);
				}
			}
		};
		dfs(dfs, x, x);

		int mx = 0, v = x;
		for (auto s : marked)
			if (uax(mx, d[s]))
				v = s;
		return pair(v, mx);
	};

	int u = furthest(0).first;
	auto [v, d] = furthest(u);

	int x = -1, y = -1;
	for (int i = 0; i < n; ++i) {
		int t = a[i];
		int s = lower_bound(all(cmp), t) - begin(cmp);
		if (s == u) x = i;
		if (s == v) y = i;
	}
	assert(x != -1 && y != -1);

	cout << x + 1 << ' ' << y + 1 << ' ' << d << '\n';
}
