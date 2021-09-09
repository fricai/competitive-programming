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

ll f(vector<int> x, vector<pair<int, int>> p) {
	sort(all(p));

	ll ans = 0;
	map<int, int> f;
	for (int i = 0, j = 0, k = 0; i < sz(p); ++i) {
		while (k + 1 < sz(x) && x[k + 1] <= p[i].first)
			++k;
		while (j < i && p[j].first <= x[k])
			--f[p[j++].second];
		auto &z = f[p[i].second];
		ans += i - j - z;
		++z;
	}
	return ans;
}

ll solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> x(n), y(m);
	for (auto &a : x)
		cin >> a;
	for (auto &a : y)
		cin >> a;

	vector<pair<int, int>> p(k);
	for (auto &[x, y] : p)
		cin >> x >> y;
	auto it = partition(all(p), [&](auto z) {
			return binary_search(all(x), z.first);
			});
	for_each(begin(p), it, [&](auto &p) {
			swap(p.first, p.second);
			});
	return f(y, {begin(p), it}) + f(x, {it, end(p)});
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
