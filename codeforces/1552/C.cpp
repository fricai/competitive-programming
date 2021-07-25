#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll solve() {
	int n, k; cin >> n >> k;

	vector<pair<int, int>> c(k);
	vector<bool> vis(n + n);

	auto order = [&](pair<int, int> &p) {
		if (p.first > p.second)
			swap(p.first, p.second);
	};
	
	for (auto &[x, y] : c)
		cin >> x >> y, --x, --y, vis[x] = vis[y] = true;

	vector<int> opt;
	rep(i, 0, n + n)
		if (!vis[i])
			opt.push_back(i);
	
	auto intersect = [](auto p, auto q) {
		if (p.first > q.first)
			swap(p, q);
		if ((q.second <= p.second) || (p.second <= q.first))
			return false;
		return true;
	};
	
	int s = n - k;
	assert(sz(opt) == s + s);
	
	ll ans = 0;
	
	rep(i, 0, s)
		c.emplace_back(opt[i], opt[i + s]);
	
	for (auto &p : c)
		order(p);
	assert(sz(c) == n);
	
	// cerr << '\n';
	// for (auto [x, y] : c)
	// 	cerr << x + 1 << ' ' << y + 1 << '\n';

	rep(i, 0, n)
		rep(j, 0, i) {
			// if (intersect(c[i], c[j]))
			// 	cerr << c[i].first + 1 << ' ' << c[i].second + 1 << " | "
			// 		<< c[j].first + 1 << ' ' << c[j].second + 1 << '\n';
			ans += intersect(c[i], c[j]);
		}
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}