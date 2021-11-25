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

	int n; cin >> n;
	vector<ll> c(n);
	for (auto &x : c) {
		cin >> x;
	}

	ll ans = 0;
	for (int l = 0; l < n; l += 2) {
		ll cur = 0, mn = 0;
		for (int r = l + 1; r < n; ++r) {
			if (~r & 1) {
				cur += c[r];
			} else {
				ll nxt = cur - c[r];
				ans += max(0ll, min(-nxt, c[l]) - max(-mn, -cur + 1) + 1);
				cur = nxt;
				uin(mn, nxt);
			}
			// cerr << cur << ' ';
		}
		// cerr << '\n';
	}
	cout << ans << '\n';
}
