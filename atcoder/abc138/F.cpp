#include <bits/stdc++.h>
#include <atcoder/modint>

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
using mint = atcoder::modint1000000007;


mint f(ll l, ll r) {
	if (l > r)
		return 0;

	vector dp(B, vector(2, vector(2, mint(0))));
	vector vis(B, vector(2, vector(2, false)));

	auto g = [&](const auto &h, int p, bool fl, bool fr) -> mint {
		if (p < 0) {
			return 1;
		}

		if (vis[p][fl][fr]) {
			return dp[p][fl][fr];
		}

		vis[p][fl][fr] = true;
		auto &res = dp[p][fl][fr];
		if (fl || (~l >> p & 1))
			res += h(h, p - 1, fl, fr || (r >> p & 1));
		if ((fl || (~l >> p & 1)) && (fr || (r >> p & 1)))
			res += h(h, p - 1, fl, fr);
		if (fr || (r >> p & 1))
			res += h(h, p - 1, (~l >> p & 1) || fl, fr);
		return res;
	};

	/*
	mint ans = 0;
	for (ll x = l; x <= r; ++x) {
		for (ll y = x; y <= r; ++y)
			ans += (x & y) == x;
	}
	*/
	return g(g, B - 1, false, false);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll l, r; cin >> l >> r;

	mint ans = 0;
	rep(b, 0, B) {
		ans += f(max(l, 1ll << b), min(r, (2ll << b) - 1));
	}
	cout << ans.val() << '\n';
}
