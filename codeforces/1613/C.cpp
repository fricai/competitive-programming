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

ll solve() {
	int n; ll h; cin >> n >> h;
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;
	a.push_back(1.6e18);

	ll l = 0, r = h;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		([&]() -> bool {
		 	ll cur = 0;
			rep(i, 1, sz(a))
				cur += min(m, a[i] - a[i - 1]);
			return cur >= h;
		 }() ? r : l) = m;
	}
	return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
