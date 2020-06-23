#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
int a[N];
int w[N];

ll solve() {
	int n, k; cin >> n >> k;

	rep(i, 0, n) cin >> a[i];
	rep(i, 0, k) cin >> w[i];
	sort(a, a + n);
	sort(w, w + k, greater<int>());

	int cnt = 0;
	rep(i, 0, k) if (w[i] == 1) ++cnt;
	ll ans = 0;
	rep(i, n - k, n) ans += a[i];
	rep(i, n - cnt, n) ans += a[i];
	int cur = 0;
	rep(i, 0, k) {
		if (w[i] > 1) {
			ans += a[cur];
			cur += w[i] - 1;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}