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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; int k; cin >> n >> k;
	int m = max(int(sqrt(n)) + 5, k);

	cerr << m << '\n';

	vector<ll> v(m + 1), w(k);
	iota(all(v), 0);
	iota(all(w), n - k + 1);

	atcoder::modint998244353 ans = 1;
	for (int p = 2; p <= m; ++p) {
		if (v[p] != p)
			continue;

		int e = 0;
		for (int q = p; q <= m; q += p) {
			int r = 0;
			while (v[q] % p == 0)
				v[q] /= p, ++r;
			if (q <= k) e -= r;
		}

		for (ll q = ((n - k) / p + 1) * p, j = q - (n - k + 1); q <= n; q += p, j += p) {
			while (w[j] % p == 0)
				w[j] /= p, ++e;
		}
		ans *= 1 + e;
	}

	for (auto x : w) if (x > 1) ans += ans;
	cout << ans.val() << '\n';
}
