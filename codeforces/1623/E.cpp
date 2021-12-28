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

	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> l(n), r(n);
	rep(i, 0, n) cin >> l[i] >> r[i], --l[i], --r[i];

	int cnt = 0;
	vector<vector<int>> paths(n);
	vector<int> id(n), inord;
	auto dfs = [&](const auto &self, int u) -> void {
		if (u < 0) return;
		id[u] = cnt;
		paths[cnt].push_back(u);
		self(self, l[u]);
		++cnt;
		inord.push_back(u);
		self(self, r[u]);
	};
	dfs(dfs, 0);

	vector<int> par(n);
	rep(i, 0, n) {
		if (~l[i]) par[l[i]] = i;
		if (~r[i]) par[r[i]] = i;
	}

	vector<int> dup(n);
	for (int i = 0, j = 0; i < n; ++i) {
		int v = inord[i];
		while (j < n && s[v] == s[inord[j]]) ++j;

		auto &p = paths[id[v]];
		assert(p.back() == v);
		int head = p.front();
		if (!dup[v] && j < n && s[v] < s[inord[j]]
				&& (head == 0 || dup[par[head]])
				&& sz(p) <= k)
			for (auto u : p)
				dup[u] = 1, --k;
		p.pop_back();
	}

	for (auto v : inord)
		cout << string(dup[v] + 1, s[v]);
	cout << '\n';
}
