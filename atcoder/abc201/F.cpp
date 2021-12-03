#include <bits/stdc++.h>
#include <atcoder/segtree>

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

constexpr ll inf = 1e18;
ll op(ll a, ll b) { return min(a, b); }
ll e() { return inf; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> pos(n);
	rep(i, 0, n) {
		int x; cin >> x;
		pos[x - 1] = i;
	}

	vector<ll> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		uin(b[i], a[i]);
		uin(c[i], a[i]);
	}

	atcoder::segtree<ll, op, e> t(n);
	vector<ll> dp(n);
	t.set(pos[0], dp[0] - a[0]);
	for (int i = 1; i < n; ++i) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
		c[i] += c[i - 1];
		dp[i] = min(b[i - 1], t.prod(0, pos[i]) + a[i - 1]);
		t.set(pos[i], dp[i] - a[i]);
	}

	ll ans = inf;
	for (int i = 0; i < n; ++i) {
		uin(ans, dp[i] + c[n - 1] - c[i]);
	}
	cout << ans << '\n';
}
