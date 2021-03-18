#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int X = 1e7 + 5;
int factors[X + X];


ll solve() {
	int c, d, x; cin >> c >> d >> x;

	ll ans = 0;
	auto f = [&](int g) {
		int y = x / g + d;
		if (y % c) return;
		y /= c;
		ans += 1ll << factors[y];
	};
	for (int k = 1; k * k <= x; ++k) {
		if (x % k) continue;
		f(k);
		if (k * k != x) f(x / k);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(p, 2, X + X) {
		if (factors[p]) continue;
		for (int q = p; q < X + X; q += p) 
			++factors[q];
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}