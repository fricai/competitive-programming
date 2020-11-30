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

const int N = 1 << 11, A = 26;
char g[N][N];
int l[A], r[A], u[A], d[A];

void solve() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> g[i];
	rep(i, 0, A) l[i] = u[i] = N, r[i] = d[i] = -1;

	int mx = -1;

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (g[i][j] == '.') continue;
			int c = g[i][j] - 'a';
			ckmax(mx, c);
			ckmin(l[c], i);
			ckmin(u[c], j);
			ckmax(r[c], i);
			ckmax(d[c], j);
		}
	}

	for (int c = mx; 0 <= c; --c) {
		if (l[c] == N) { l[c] = l[c + 1]; r[c] = r[c + 1]; u[c] = u[c + 1]; d[c] = d[c + 1]; continue; }
		if (l[c] != r[c] && u[c] != d[c]) return void(cout << "NO\n");
		if (l[c] == r[c]) {
			int k = l[c];
			for (int j = u[c]; j <= d[c]; ++j) {
				if (g[k][j] != c + 'a' && g[k][j] != '$') return void(cout << "NO\n");
				g[k][j] = '$';
			}
		} else {
			int k = u[c];
			for (int i = l[c]; i <= r[c]; ++i) {
				if (g[i][k] != c + 'a' && g[i][k] != '$') return void(cout << "NO\n");
				g[i][k] = '$';
			}
		}
	}
	
	cout << "YES\n" << mx + 1 << '\n';
	for (int c = 0; c <= mx; ++c)
		cout << l[c] + 1 << ' ' << u[c] + 1 << ' ' << r[c] + 1 << ' ' << d[c] + 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}