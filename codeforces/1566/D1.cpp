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

int solve() {
	int n, m; cin >> n >> m;
	vector a(vector(n, vector(m, 0)));
	for (auto &v : a)
		for (auto &x : v)
			cin >> x;

	vector<pair<int, int>> p(m);
	rep(i, 0, m) p[i] = {a[0][i], -i};
	sort(all(p));
	vector<int> seat(m);
	rep(i, 0, m) seat[-p[i].second] = i;

	vector<bool> taken(m, false);
	int ans = 0;
	rep(i, 0, m) {
		rep(j, 0, seat[i])
			ans += taken[j];
		taken[seat[i]] = true;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
