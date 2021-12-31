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

vector<int> get_ord(const vector<int> &a) {
	vector<int> ord(sz(a));
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) {
			return a[i] < a[j];
		});
	return ord;
}

string solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	vector<int> b(n);
	for (auto &x : b)
		cin >> x;
	
	int win_a = max_element(all(a)) - begin(a);
	int win_b = max_element(all(b)) - begin(b);

	vector<vector<int>> g(n);

	// if a[u] > a[v], add an edge from v -> u

	auto ord_a = get_ord(a);
	rep(i, 1, n) g[ord_a[i - 1]].push_back(ord_a[i]);

	auto ord_b = get_ord(b);
	rep(i, 1, n) g[ord_b[i - 1]].push_back(ord_b[i]);

	string vis(n, '0');
	auto dfs = [&](const auto &self, int u) -> void {
		if (vis[u] == '1') return;
		vis[u] = '1';
		for (auto v : g[u])
			self(self, v);
	};
	dfs(dfs, win_a);
	dfs(dfs, win_b);
	return vis;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
