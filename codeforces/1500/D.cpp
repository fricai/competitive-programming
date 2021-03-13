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

const int B = 12, Q = 11, N = 1500 + 5;

int n, q;
using V = array<int, Q>;
int tmp[Q + Q];
int cnt(const V& a) {
	int res = 0;
	rep(i, 0, Q) res += a[i] > 0;
	return res;
}

V operator+(const V &a, const V &b) {
	V c;
	int i = 0, j = 0, k = 0;
	for ( ; i < Q && j < Q && k < Q && a[i] && b[j]; ++k) {
		if (a[i] < b[j]) c[k] = a[i++];
		else if (a[i] > b[j]) c[k] = b[j++];
		else c[k] = a[i++], ++j;
	}
	for (; i < Q && k < Q && a[i]; ++i, ++k) c[k] = a[i];
	for (; j < Q && k < Q && b[j]; ++j, ++k) c[k] = b[j];
	rep(j, k, Q) c[j] = 0;
	return c;
}

V t[2][N][N];
bool vis[N][N];

int f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	rep(i, 0, n) rep(j, 0, n) cin >> t[0][i][j][0];

	for (int level = 1, p = 0, d = 1; level < B; ++level, p ^= 1, d <<= 1) {
		rep(x, 0, n - d)
			rep(y, 0, n - d)
				t[!p][x][y] = t[p][x][y] + t[p][x + d][y] + t[p][x][y + d] + t[p][x + d][y + d];
		rep(x, 0, n) {
			rep(y, 0, n) {
				if (vis[x][y]) continue;
				if (cnt(t[!p][x][y]) <= q && x + 2 * d <= n && y + 2 * d <= n) continue;
				vis[x][y] = 1;
				auto g = [&](int k) {
					if (x + k > n || y + k > n) return q + 1;
					k -= d;
					return cnt(t[p][x][y] + t[p][x + k][y] + t[p][x][y + k] + t[p][x + k][y + k]);
				};
				int l = d, r = 2 * d;
				while (r - l > 1) {
					int m = l + (r - l) / 2;
					(g(m) <= q ? l : r) = m;
				}
				++f[l];
			}	
		}
	}

	per(i, 1, n) f[i] += f[i + 1];
	for (int i = 1; i <= n; ++i) cout << f[i] << '\n';
}