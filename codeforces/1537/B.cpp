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

ll dist(pair<int, int> p, pair<int, int> q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

void solve() {
	int n, m, i, j; cin >> n >> m >> i >> j;
	
	pair<int, int> o = {i, j};
	pair<int, int> p[4] = {{1, 1}, {n, 1}, {1, m}, {n, m}};
	
	ll res = -1;

	int T = 0;
	rep(S, 0, 1 << 4) {
		if (__builtin_popcount(S) != 2) continue;
	
		vector<pair<int, int>> v;
		rep(j, 0, 4) if (S >> j & 1) v.push_back(p[j]);
		if (uax(res, dist(v[0], v[1]) + dist(o, v[0]) + dist(o, v[1])))
			T = S;
	}
	
	assert(__builtin_popcount(T) == 2);
	rep(j, 0, 4)
		if (T >> j & 1)
			cout << p[j].first << ' ' << p[j].second << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}