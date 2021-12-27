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
	int n; cin >> n;
	ll k; cin >> k;

	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;
	sort(all(a));
	ll sum = accumulate(all(a), 0ll);
	if (sum <= k) return 0;

	ll l = 0, r = sum;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		([&]() -> bool {
			ll cur = 0;
			for (int e = n - 1, i = 1; e >= 0; --e, ++i) {
				if (e <= m && (e + 1) * (a[0] - m + e) + cur <= k)
					return true;
				if (i < n) cur += a[i];
			}
			return false;
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
