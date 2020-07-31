#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 7;
int grid[N][N], a[N], b[N], t[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, h; cin >> n >> m >> h;
	rep(i, 0, m) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	rep(i, 0, n) rep(j, 0, m) cin >> t[i][j];
	rep(j, 0, m) {
		rep(i, 0, n) {
			if (!t[i][j]) continue;
			if (b[i] < a[j]) continue;
			grid[i][j] = a[j];
			break;
		}
	}
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (!t[i][j]) continue;
			if (b[i] > a[j]) continue;
			if (grid[i][j]) continue;
			grid[i][j] = b[i];
		}
	}
	rep(i, 0, n) rep(j, 0, m) if (t[i][j] && !grid[i][j]) grid[i][j] = 1;
	rep(i, 0, n) {
		rep(j, 0, m) cout << grid[i][j] << ' ';
		cout << '\n';
	}
}