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

void solve() {
	int n; ll m; cin >> n >> m;

	vector<ll> x(n);
	for (auto &a : x) cin >> a;

	vector<string> dir(n);
	for (auto &s : dir) cin >> s;

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) {
		return x[i] < x[j];
	});

	vector<int> ans(n, -1);
	stack<pair<int, ll>> st[2];

	
	for (auto i : ord) {
		auto &s = st[x[i] & 1];
		if (dir[i] == "L") {
			if (s.empty()) s.push({i, -x[i]});
			else {
				auto [j, y] = s.top(); s.pop();
				ans[i] = ans[j] = (x[i] - y) / 2;
			}
		} else s.push({i, x[i]});
	}

	rep(b, 0, 2) {
		auto &s = st[b];
		while (sz(s) > 1) {
			auto [i, one] = s.top(); s.pop();
			auto [j, two] = s.top(); s.pop();
			
			ans[i] = ans[j] = m - (one + two) / 2;
		}
	}

	for (auto x : ans) cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}