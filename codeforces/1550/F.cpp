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

struct dsu {
	vector<int> nxt;
	dsu(int n) : nxt(n, -1) { }
	int head(int u) {
		return nxt[u] < 0 ? u : nxt[u] = head(nxt[u]);
	}
	bool join(pair<int, int> p) {
		return join(p.first, p.second);
	}
	bool join(int u, int v) {
		u = head(u); v = head(v);
		if (u == v) return 0;
		return nxt[u] = v, 1;
	}
	bool same(int u, int v) {
		return head(u) == head(v);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, s, d; cin >> n >> q >> s >> d, --s;
	
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<pair<int, int>> edges;
	/*
		i < j
		
		if a[j] - a[i] <= d,
			don't add edges i < x < y < j
		if a[j] - a[i] >= d,
			don't add edges (x, y), x < i < j < y
	*/

	auto add = [&](int i, int j) {
		edges.emplace_back(i, j);
	};

	for (int i = 0, j = 0; i < n; ++i) {
		uax(j, i);
		while (j < n && a[j] - a[i] <= d)
			add(i, j++);
		--j;
	}
	
	for (int i = 0, j = 0; j < n; ++j) {
		uax(i, 0);
		while (i < j && a[j] - a[i] >= d)
			add(i++, j);
		--i;
	}
	
	auto cost = [&](auto p) {
		return abs(d - abs(a[p.first] - a[p.second]));
	};
	sort(all(edges), [&](auto x, auto y) {
		return cost(x) < cost(y);
	});

	vector<tuple<int, int, int>> ev(q);
	
	int idx = 0;
	for (auto &[k, i, cur] : ev)
		cin >> i >> k, --i, cur = idx++;
	sort(all(ev));

	vector<bool> ans(q);

	dsu D(n);

	idx = 0;
	for (auto [k, i, cur] : ev) {
		while (idx < sz(edges) && cost(edges[idx]) <= k)
			D.join(edges[idx++]);
		ans[cur] = D.same(s, i);
	}
	
	for (auto b : ans)
		cout << (b ? "Yes" : "No") << '\n';
}