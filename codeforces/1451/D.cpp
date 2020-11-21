#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll d, k;
// bool check(ll x, ll y) {
// 	return x * x + y * y <=
// }

int f(ll x) {
	// return largest y such that k^2 (x^2 + y^2) <= d^2 and k | y assuming k | x
	ll y = floor(sqrt(ld(d * d) / ld (k * k) - x * x));
	assert(k * k * (x * x + y * y) <= d * d);
	assert(d * d < k * k * (x * x + (y + 1) * (y + 1)));
	return y;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		cin >> d >> k;
		bool ans = 0;
		for (int x = 0; k * x <= d; ++x) {
			int y = f(x);
			if (f(y) == x) ans ^= 1;
		}
		// while (sz(v) > 1) {
		// 	vector<bool> t(sz(v) - 1);
		// 	rep(i, 1, sz(v)) t[i - 1] = !v[i - 1] && !v[i];
		// 	swap(v, t);
		// }
		cout << (ans ? "Utkarsh" : "Ashish") << '\n';
	}
}