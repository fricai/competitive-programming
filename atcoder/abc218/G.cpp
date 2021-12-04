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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int inf = 1e9 + 10;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dp(n, -1);
	ost<pair<int, int>> s;
	auto init = [&](const auto &self, int u, bool b) -> void {
		s.insert({a[u], u});
		if (g[u].empty()) {
			if (sz(s) & 1) dp[u] = s.find_by_order(sz(s) / 2)->first;
			else dp[u] = (s.find_by_order(sz(s) / 2 - 1)->first + s.find_by_order(sz(s) / 2)->first) / 2;
		} else dp[u] = b ? -inf : +inf;
		for (auto v : g[u]) {
			g[v].erase(find(all(g[v]), u));
			self(self, v, !b);
			if (b) uax(dp[u], dp[v]);
			else uin(dp[u], dp[v]);
		}
		s.erase({a[u], u});
	};
	init(init, 0, 1);

	cout << dp[0] << '\n';
}
