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

	ll n, s, t, a, b; cin >> n >> s >> t >> a >> b;

	ll r = sqrt(ld(2) * b * n / a);
	if (r > t) r = t;

	ld mn = b * n;
	r -= 2;
	rep(i, 0, 5) {
		if (r > 0 && r <= t) {
			uin(mn, ld(b) * n / r + ld(a) * (r - 1) / 2);
		}
		++r;
	}

	cout << fixed << setprecision(10);
	if (s <= t) cout << min(ld(a) * (t - s), mn) << '\n';
	else cout << mn << '\n';
}
