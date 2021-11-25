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

constexpr int B = 60;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, l, r; cin >> n >> l >> r;

	ll ans = 0;
	per(k, 0, B) {
		if (n >> k & 1) {
			ans += max(0ll, min(r + 1, 1ll << (k + 1)) - max(1ll << k, l));
		}
	}
	cout << ans << '\n';
}
