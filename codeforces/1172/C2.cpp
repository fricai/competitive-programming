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

const int mod = (119 << 23) + 1, N = 1 << 18, M = 3e3 + 10;
ll S, T;
int a[N], w[N];
int _f[M][M], _g[M][M];
bool vis_f[M][M], vis_g[M][M];

int inv(ll a) {
	ll res = 1; a %= mod;
	for (int e = mod - 2; e; e >>= 1, a = a * a % mod)
		if (e & 1) res = res * a % mod;
	return res;
}

ll f(int i, ll s, ll t) {
	if (i == 0) return 1;
	int x = s - S, y = T - t;
	if (vis_f[x][y]) return _f[x][y];
	vis_f[x][y] = 1;
	return _f[x][y] = ((s + 1) * f(i - 1, s + 1, t) + t * f(i - 1, s, t - 1)) % mod * inv(s + t) % mod;
}

ll g(int i, ll s, ll t) {
	if (i == 0) return 1;
	int x = s - S, y = T - t;
	if (vis_g[x][y]) return _g[x][y];
	vis_g[x][y] = 1;
	return _g[x][y] = (s * g(i - 1, s + 1, t) + (t - 1) * g(i - 1, s, t - 1)) % mod * inv(s + t) % mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> w[i];

	S = 0;
	T = 0;
	rep(i, 0, n) {
		T += w[i];
		S += a[i] * w[i];
		T -= a[i] * w[i];
	}
	rep(i, 0, n) cout << (a[i] ? f : g)(m, S, T) * w[i] % mod << '\n';
}