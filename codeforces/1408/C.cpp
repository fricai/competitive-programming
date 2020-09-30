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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;
int n, x, a[N], b[N];
const ld eps = 1e-9;

ld pos(ld t, int c[]) {
	int p = 0, v = 1;
	rep(i, 0, n) {
		if (p + v * t < c[i]) break;
		t -= ld(c[i] - p) / v;
		p = c[i];
		++v;
	}
	return p + v * t;
}

bool ok(ld t) { return pos(t, a) + pos(t, b) >= x; }

ld solve() {
	cin >> n >> x;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) b[i] = x - a[n - i - 1];
	// rep(i, 0, n) cerr << a[i] << ' ';
	// cerr << '\n';
	// rep(i, 0, n) cerr << b[i] << ' ';
	// cerr << '\n';
	ld l = 0, r = x;
	// cout << pos(53.700000000000000, a) << ' ' << pos(53.700000000000000, b) << '\n';
	while (r - l > eps) {
		ld m = (l + r) / 2;
		(ok(m) ? r : l) = m;
	}
	return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << fixed << setprecision(9) << solve() << '\n';
}