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

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	auto z = a;
	for (auto &x : z) x = (m - x) % m;
	for (auto x : b) z.push_back(x);
	sort(all(z)); z.erase(unique(all(z)), end(z));

	auto val = [&](int x) { return lower_bound(all(z), x) - begin(z) + n; };

	int p = sz(z);

	vector<vector<pair<int, int>>> g(n + p);
	rep(i, 0, n) {
		g[i].emplace_back(val((m - a[i]) % m), 0);
		g[val(b[i])].emplace_back(i, 0);
	}
	rep(i, 0, p - 1) {
		g[i + n].emplace_back(i + 1 + n, z[i + 1] - z[i]);
	}
	g[p - 1 + n].emplace_back(n, z[0] - z[p - 1] + m);

	vector d(n + p, inf);
	priority_queue<pair<ll, int>> q;
	d[0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		auto [dis, u] = q.top(); q.pop();
		if (-dis != d[u])
			continue;
		for (auto [v, w] : g[u]) {
			if (uin(d[v], w + d[u])) {
				q.push({-d[v], v});
			}
		}
	}
	cout << d[n - 1] << '\n';
}
