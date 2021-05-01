#include <bits/stdc++.h>
#include <atcoder/dsu>

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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	
	vector<bool> dead(n, 0);
	
	rep(i, 0, m) {
		int x; cin >> x;
		dead[x] = 1;
	}
	
	vector<pair<int, int>> res;

	atcoder::dsu d(n);
	auto add = [&](int u, int v) {
		if (d.same(u, v)) return;
		res.emplace_back(u, v);
		d.merge(u, v);
	};

	rep(i, 0, n)
		if (!dead[i] && !d.same(0, i))
			rep(u, 0, n) add(u, u ^ i);
	if (sz(d.groups()) > 1) return cout << "-1\n", 0;
	for (auto [u, v] : res) cout << u << ' ' << v << '\n';
}