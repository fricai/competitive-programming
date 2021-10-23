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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, k; cin >> x >> k;
	vector<int> e(k);
	for (auto &t : e)
		cin >> t;

	// f(t, x) = sand in glass A at time t if a = x
	//
	// f(t, x) = l + c if x <= l
	// 	= x + c if l < x <= r
	//  	= r + c if r < x
	//
	//  at time t ~and it's not a breakpoint~
	//  f(t + k, x) = max(0, f(t, x) - k) if A is on top
	//  f(t + k, x) = min(X, f(t, x) + k) if A is on bottom
	//
	//  and if t + 1 is a breakpoint, only the "on top-ness" changes
	
	ll l = 0, r = x, c = 0, lst = 0;
	auto f = [&](ll a) {
		return min(r, max(a, l)) + c;
	};

	bool on_top = true;

	auto update_lst = [&](ll t, bool flip) {
		assert(t >= lst);
		ll d = t - lst;
		if (on_top) {
			if (l + c >= d) {
				c -= d;
			} else if (r + c >= d) {
				c -= d;
				l = -c;
			} else {
				// identically 0
				l = r = 0;
				c = 0;
			}
		} else {
			if (r + c + d <= x) {
				c += d;
			} else if (l + c + d <= x) {
				c += d;
				r = x - c;
			} else {
				// identically x
				l = r = 0;
				c = x;
			}
		}
		lst = t;
		on_top ^= flip;
	};

	int q; cin >> q;
	for (int i = 0; q--; ) {
		int t, a; cin >> t >> a;

		while (i < k && e[i] <= t) {
			update_lst(e[i], true);
			++i;
		}
		update_lst(t, false);

		cout << f(a) << '\n';
	}
}
