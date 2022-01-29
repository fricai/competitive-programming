#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll l, w; cin >> n >> l >> w;

	vector<pair<ll, ll>> st;
	rep(i, 0, n) {
		ll x; cin >> x;
		// merge [x, x + w)
		if (st.empty()) st.emplace_back(x, x + w);
		else {
			auto [p, q] = st.back();
			// [p, q) union [x, x + w)
			// [p, ..., q - 1] [x
			// if x == q
			// if x <= q merge
			if (x <= q) {
				st.pop_back();
				st.emplace_back(p, x + w);
			} else {
				st.emplace_back(x, x + w);
			}
		}
	}

	vector<ll> z;
	z.push_back(0);
	for (auto [x, y] : st) {
		z.push_back(x);
		z.push_back(y);
	}
	z.push_back(l);
	assert(~sz(z) & 1);

	ll ans = 0;
	for (int i = 0; i + 1 < sz(z); i += 2) {
		// [z[i], z[i + 1])
		// [z[i], z[i] + k * w)
		// [z[i], z[i + 1]) is a subset of [z[i], z[i] + k * w)
		// z[i + 1] <= z[i] + k * w
		// <=> (z[i + 1] - z[i])/w <= k
		// <=> k = ceil((z[i + 1] - z[i]) / w)
		ans += (z[i + 1] - z[i] + w - 1) / w;
	}
	cout << ans << '\n';
}
