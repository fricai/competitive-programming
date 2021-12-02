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

constexpr int X = 1e6 + 5;
bool sieve[X];

ll count(vector<int> x) {

	int n = sz(x);
	ll ret = 0;
	int prime_loc = -1;
	for (int l = 0, r = 0; l < n; ++l) {
		if (r < l) {
			r = l;
			prime_loc = -1;
		}
		while (r < n) {
			if (x[r] == 1) {
				++r;
			} else if (!sieve[x[r]]) {
				if (prime_loc < 0) {
					prime_loc = r;
					++r;
				} else {
					break;
				}
			} else break;
		}

		if (prime_loc >= 0) {
			ret += r - max(prime_loc, l + 1);
		}
		if (!sieve[x[l]]) {
			prime_loc = -1;
		}
	}

	return ret;
}

ll solve() {
	int n, e; cin >> n >> e;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	vector<vector<int>> v(e);
	rep(i, 0, n) v[i % e].push_back(a[i]);

	ll ans = 0;
	for (auto &x : v)
		ans += count(x);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve[0] = sieve[1] = true;
	for (int i = 2; i < X; ++i) {
		if (sieve[i])
			continue;
		for (int j = i + i; j < X; j += i) {
			sieve[j] = true;
		}
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
