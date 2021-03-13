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

const int N = 1 << 19;
const ll inf = 1e18;
int a[N], b[N], idx[N + N];
vector<ll> v;
ll mod;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if ((a - b) % g != 0) return -1;
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

ll f(ll d) {
	ll del = 0;
	for (auto x : v) {
		if (d <= x) continue;
		del += (d - x + mod - 1) / mod;
	}
	return d - del;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; ll k; cin >> n >> m >> k;
	rep(i, 0, n) cin >> a[i], idx[a[i]] = i + 1;
	rep(i, 0, m) {
		cin >> b[i];
		if (idx[b[i]]) {
			int j = idx[b[i]] - 1;
			auto ok = crt(j, n, i, m);
			if (ok < 0) continue;
			v.push_back(ok);
		}
	}
	mod = n;
	mod *= m;
	mod /= gcd(n, m);

	// for (int x = 0; ; ++x) {
	// 	auto res = f(x);
	// 	cout << x << ' ' << res << '\n';
	// 	if (res == k) break;
	// }
	ll l = 0, r = inf;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		(f(m) < k ? l : r) = m;
	}
	cout << r << '\n';
}