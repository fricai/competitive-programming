#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <atcoder/dsu>

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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	vector<tuple<int, int, int, int>> edges(m + q);

	{
	int id = -m;
	for (auto &[c, u, v, t] : edges) {
		cin >> u >> v >> c; --u; --v;
		t = id++;
	}
	}

	vector<bool> ans(q, false);

	sort(all(edges));
	atcoder::dsu d(n);
	for (auto [c, u, v, t] : edges) {
		if (d.same(u, v)) continue;
		if (t < 0) d.merge(u, v);
		else ans[t] = true;
	}

	for (auto v : ans)
		cout << (v ? "Yes" : "No") << '\n';
}
