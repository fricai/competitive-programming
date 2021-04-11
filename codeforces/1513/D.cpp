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

const int B = 18, N = 1 << B;

int s[B + 1][N];

int g(int i, int j) {
	int d = 31 - __builtin_clz(j - i);
	return gcd(s[d][i], s[d][j - (1 << d)]);
}

ll solve() {
	int n, p; cin >> n >> p;
	vector<int> a(n);

	bool one = 0;
	for (auto &x : a) cin >> x, one |= x == 1;
	if (one) return n - 1;

	rep(i, 0, n) s[0][i] = a[i];
	for (int j = 0, d = 1; j < B; ++j, d <<= 1)
		for (int i = 0; i + d < n; ++i)
			s[j + 1][i] = gcd(s[j][i], s[j][i + d]);
	
	set<int> t = {-1, n};
	for (int i = 0; i < n; ++i) t.insert(i);

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int x, int y) {
		return a[x] < a[y];
	});

	ll ans = 0;
	// cerr << '\n';
	for (int j = 0; j < n; ++j) {
		int i = ord[j];
		if (a[i] > p) break;
		int L = 0, R = n - 1;

		auto f = [&](int d) {
			if (g(0, i + 1) % d) {
				int l = 0, r = i;
				// d | gcd(a[r], a[r + 1], ..., a[i]) 
				// no d | gcd(a[l], ..., a[i])
				while (r - l > 1) {
					int m = (l + r) / 2;
					(g(m, i + 1) % d != 0 ? l : r) = m;
				}
				ckmax(L, r);
			}
			if (g(i, n) % d) {
				int l = i, r = n - 1;
				// d | gcd(a[i], a[i + 1], ..., a[l])
				// no d | gcd(a[i], a[i + 1], ..., a[r]);
				while (r - l > 1) {
					int m = (l + r) / 2;
					(g(i, m + 1) % d != 0 ? r : l) = m;
				}
				ckmin(R, l);
			}
		};

		int x = a[i];
		for (int d = 2; d * d <= x; ++d) {
			if (x % d) continue;
			int y = 1;
			while (x % d == 0) x /= d, y *= d;
			f(y);
		}
		if (x > 1) f(x);

		// cerr << *t.upper_bound(L) << '\n';
		for (auto it = t.upper_bound(L); *it <= R; ) {
			ans += a[i];
			t.erase(it++);
		}

		// cerr << i << ' ' << L << ' ' << R << '\n';
		// for (auto x : t) cerr << x << ' ';
		// cerr << '\n';
		// cerr << '\n';

	}

	for (int i = 3; i < sz(t); ++i) ans += p;
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}