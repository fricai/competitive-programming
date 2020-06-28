#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
ll a[N];

ll solve() {
	ll n, k; cin >> n >> k;
	rep(i, 0, n) {
		cin >> a[i];
		a[i] %= k;
		a[i] = k - a[i];
		a[i] %= k;
	}

	sort(a, a + n);
	rep(i, 1, n)
		if (a[i] == a[i - 1] % k)
			a[i] = a[i - 1] + k;
	sort(a, a + n);
	rep(i, 0, n) a[i] %= k;
	// rep(i, 0, n) cerr << a[i] << ' '; cerr << '\n';

	ll ans = 0, x = 0;
	rep(i, 0, n) {
		if (a[i] == 0) continue;
		ans += a[i] - x + 1;
		if (a[i] < x) ans += k;
		x = (a[i] + 1) % k;
		// cerr << ans << ' ';
	}
	// cerr << '\n';
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}