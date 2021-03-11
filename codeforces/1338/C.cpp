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

ll f(ll n) {
	
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	ll sz = 1, res = 0;
	while (sz <= n) sz <<= 2;
	sz >>= 2;

	assert(sz <= n && n < 4 * sz);
	
	ll z = (n - sz) / 3;
	if (z % 4 == 0) {
		
	} else if (z % 4 == 1) {
		if (n % 3 == 1) {
			res |= 1;
		} else if (n % 3 == 2) {
			res |= 2;
		} else if (n % 3 == 0) {
			res |= 3;
		}
	} else if (z % 4 == 2) {
		if (n % 3 == 1) {
			res |= 2;
		} else if (n % 3 == 2) {
			res |= 3;
		} else if (n % 3 == 0) {
			res |= 1;
		}
	} else if (z % 4 == 3) {
		if (n % 3 == 1) {
			res |= 3;
		} else if (n % 3 == 2) {
			res |= 1;
		} else if (n % 3 == 0) {
			res |= 2;
		}
	}
	
	// cerr << res << '\n';

	ll m = n;
	while ((m - sz) % 12 != 0) --m;
	if (n % 3 == 1) {
		res |= f(m / 4) << 2; 
	} else if (n % 3 == 2) {
		res |= f(m / 4 + 1) << 2;
	} else if (n % 3 == 0) {
		res |= f(m / 4 + 2) << 2;
	}

	return res;
}

ll solve() {
	ll n; cin >> n;
	return f(n);
}

// const int N = 256;
// int f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// for (int i = 0; i < N; i += 3) {
	// 	set<int> s;
	// 	rep(j, 0, i) s.insert(f[j]);
	// 	int x = 1;
	// 	while (s.count(x)) ++x;
	// 	f[i] = x;
	// 	s.insert(x);
	// 	rep(j, 0, i) s.insert(x ^ f[j]);
	// 	int y = x + 1;
	// 	while (s.count(y)) ++y;
	// 	f[i + 1] = y;
	// 	f[i + 2] = x ^ y;
	// }
	
	// rep(i, 0, N) {
	// 	if (i % 3 == 0) cerr << "_____________\n";
	// 	cerr << bitset<8>(f[i]) << ' ' << f[i] << ' ' << i + 1 << '\n';
	// }

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}