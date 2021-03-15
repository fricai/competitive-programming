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

const int M = (119 << 23) + 1, N = 1 << 6, X = 1 << 13;
ll inv[X];
ll S, T;
int a[N], w[N];
int _f[N + N][N][N], _g[N + N][N][N];
bool vis_f[N + N][N][N], vis_g[N + N][N][N];

ll f(int w, int i, int s, int t) {
	if (w < 0) return 0;
	if (i == 0) return w;
	int x = s - S, y = T - t;
	if (vis_f[w][x][y]) return _f[w][x][y];
	vis_f[w][x][y] = 1;
	return _f[w][x][y] = (w * f(w + 1, i - 1, s + 1, t) + (s - w) * f(w, i - 1, s + 1, t) + t * f(w, i - 1, s, t - 1)) % M * inv[s + t] % M;
}

ll g(int w, int i, int s, int t) {
	if (w < 0) return 0;
	if (i == 0) return w;
	int x = s - S, y = T - t;
	if (vis_g[w][x][y]) return _g[w][x][y];
	vis_g[w][x][y] = 1;
	return _g[w][x][y] = (w * g(w - 1, i - 1, s, t - 1) + s * g(w, i - 1, s + 1, t) + (t - w) * g(w, i - 1, s, t - 1)) % M * inv[s + t] % M;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = 1;
	rep(i, 2, X) inv[i] = M - M / i * inv[M % i] % M;
	
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
	rep(i, 0, n) cout << (a[i] ? f(w[i], m, S, T) : g(w[i], m, S, T)) << '\n';
}