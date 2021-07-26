#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	map<int, vector<int>> cnt;
	rep(i, 0, n) {
		int x; cin >> x;
		for (int p = 2; p * p <= x; ++p) {
			if (x % p) continue;
			int k = 0;
			while (x % p == 0) x /= p, ++k;
			cnt[p].push_back(k);
		}
		if (x > 1) cnt[x].push_back(1);
	}

	ll ans = 1;
	for (auto [p, v] : cnt) {
		if (sz(v) < n - 1)
			continue;
		int k = 0;
		if (sz(v) == n) {
			nth_element(begin(v), begin(v) + 1, end(v));
			k = v[1];
		} else k = *min_element(all(v));
		for (int i = 0; i < k; ++i) ans *= p;
	}
	cout << ans << '\n';
}