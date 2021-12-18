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

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll l = 0, r = inf / k;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		ll s = 0;
		for (auto x : a) s += min(m, x);
		(k * m <= s ? l : r) = m;
	}
	cout << l << '\n';
}
