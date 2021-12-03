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

	ll n, a, b, p, q, r, s; cin >> n >> a >> b >> p >> q >> r >> s;
	for (ll i = p; i <= q; ++i) {
		for (ll j = r; j <= s; ++j) {
			ll k = i - a;
			cout << (
					(j == b + k && max(1 - a, 1 - b) <= k && k <= min(n - a, n - b)) ||
					(j == b - k && max(1 - a, b - n) <= k && k <= min(n - a, b - 1))
				? "#" : "."
				);
		}
		cout << '\n';
	}
}
