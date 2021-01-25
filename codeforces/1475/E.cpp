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

const int M = 1e9 + 7, N = 1 << 10;
ll f[N], fi[N], inv[N];

int nCr(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * fi[k] % M * fi[n - k] % M;
}

int solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(rall(a));

	int l = k - 1, r = k - 1;
	while (l >= 0 && a[l] == a[k - 1]) --l;
	while (r < n && a[r] == a[k - 1]) ++r;

	return nCr(r - l - 1, k - l - 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = f[1] = fi[0] = fi[1] = inv[1] = 1;
	rep(i, 2, N) {
		inv[i] = M - M / i * inv[M % i] % M;
		f[i] = i * f[i - 1] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}