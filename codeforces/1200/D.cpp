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

const int N = 1 << 11;
char g[N][N], h[N][N];
int a[N][N], b[N][N], p[N][N];
bool yes[N];

void solve(int n, int k, char g[][N], int a[][N]) {
	rep(i, 0, n) rep(j, 0, n) p[i + 1][j] = p[i][j] + (g[i][j] != 'W');
	// rep(i, 0, n + 1) {
	// 	rep(j, 0, n) cerr << p[i][j] << ' ';
	// 	cerr << '\n';
	// }

	auto new_created = [&](int i, int j) { return p[n][j] != 0 && p[k + i][j] - p[i][j] == p[n][j]; };

	rep(i, 0, n - k + 1) {
		int col = 0;
		rep(j, 0, k) if (new_created(i, j)) ++col;
		a[i][0] = col;
		rep(j, 0, n - k) {
			if (new_created(i, j)) --col;
			if (new_created(i, j + k)) ++col;
			a[i][j + 1] = col;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> g[i][j];
			h[j][i] = g[i][j];
		}
	}
	int cnt = 0;
	rep(i, 0, n) {
		bool yes = true;
		rep(j, 0, n) if (g[i][j] != 'W') yes = false;
		cnt += yes;
	}
	rep(i, 0, n) {
		bool yes = true;
		rep(j, 0, n) if (g[j][i] != 'W') yes = false;
		cnt += yes;
	}
	solve(n, k, g, a);
	solve(n, k, h, b);

	int del = 0;
	rep(i, 0, n - k + 1) rep(j, 0, n - k + 1) ckmax(del, a[i][j] + b[j][i]);
	cout << del + cnt << '\n';
}