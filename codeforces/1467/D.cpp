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

const int N = 1 << 13, M = 1e9 + 7;
ll a[N];

template<class S, class T> void add(S &x, T y) { x += y; if (M <= x) x -= M; }
template<class S, class T> void sub(S &x, T y) { x -= y; if (x < 0) x += M; }

int n, k, q;
ll ways[N], f[N][N];

using ull = unsigned long long;
ull modmul(ull a, ull b) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i], f[i][0] = 1;

	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			f[i][j] = f[i - 1][j - 1];
			add(f[i][j], f[i + 1][j - 1]);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int r = 0; r <= k; ++r)
			add(ways[i], modmul(f[i][r], f[i][k - r]));
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) add(ans, modmul(ways[i], a[i]));

	while (q--) {
		int i; cin >> i;
		sub(ans, modmul(ways[i], a[i]));
		cin >> a[i];
		add(ans, modmul(ways[i], a[i]));
		cout << ans << '\n';
	}
}