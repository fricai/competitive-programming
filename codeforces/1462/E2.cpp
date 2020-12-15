#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int M = 1e9 + 7;
const int N = 1 << 18;
int a[N], nxt[N];
ll f[N], fi[N], inv[N];

int nCr(int n, int k) {
	if (n < 0 || k > n || k < 0) return 0;
	return f[n] * fi[k] % M * fi[n - k] % M;
}

int solve() {
	int n; cin >> n;
	int m, k; cin >> m >> k;
	
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);

	int ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] <= k) ++j;
		ans += nCr(j - i - 1, m - 1);
		if (M <= ans) ans -= M;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = f[0] = f[1] = fi[0] = fi[1] = 1;
	rep(i, 2, N) {
		inv[i] = M - M / i * inv[M % i] % M;
		f[i] = i * f[i - 1] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}