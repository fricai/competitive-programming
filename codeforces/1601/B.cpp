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

constexpr int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	rep(i, 0, n) cin >> a[i + 1];
	rep(i, 0, n) cin >> b[i + 1];

	int sz = 1;
	while (sz <= n + 1)
		sz <<= 1;

	vector<vector<pair<int, int>>> g(n + 10 + 2 * sz);

	int shift = n + 1;

	vector<int> leaf(sz(g), -1);

	auto build = [&](const auto &self, int v, int l, int r) -> void {
		assert(v + shift < sz(g));

		if (r - l == 1) {
			g[v + shift].emplace_back(l + b[l], 0);
			leaf[v + shift] = l;
			return;
		}

		int m = (l + r) / 2;
		self(self, v << 1|0, l, m);
		self(self, v << 1|1, m, r);

		g[v + shift].emplace_back((v << 1|0) + shift, 0);
		g[v + shift].emplace_back((v << 1|1) + shift, 0);
	};
	build(build, 1, 0, n + 1);

	for (int i = 1; i <= n; ++i) {
		int lo = i - a[i], hi = i + 1;
		auto connect = [&](const auto &self, int v, int l, int r) -> void {
			if (hi <= l || r <= lo)
				return;
			if (lo <= l && r <= hi) {
				g[i].emplace_back(v + shift, 1);
				return;
			}

			int m = (l + r) / 2;
			self(self, v << 1|0, l, m);
			self(self, v << 1|1, m, r);
		};
		connect(connect, 1, 0, n + 1);
	}

	vector<int> p(sz(g)), d(sz(g), inf);
	deque<int> q = {n};
	d[n] = 0;

	while (!q.empty()) {
		auto u = q.front();
		q.pop_front();

		for (auto [v, cost] : g[u]) {
			if (uin(d[v], d[u] + cost)) {
				p[v] = u;
				if (cost == 1)
					q.push_back(v);
				else
					q.push_front(v);
			}
		}
	}

	if (d[0] == inf)
		return cout << "-1\n", 0;

	cout << d[0] << '\n';

	vector<int> ans;
	for (int u = 0; leaf[u] != n && u != n; u = p[u])
		if (leaf[u] != -1) {
			ans.push_back(leaf[u]);
		}

	reverse(all(ans));
	for (auto v : ans)
		cout << v << ' ';
	cout << '\n';
}
