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

const int N = 1 << 9;
char c[N][N], d[N][N];
int n;

void solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> c[i];
	int k = 0;
	rep(x, 0, n) rep(y, 0, n) k += c[x][y] == 'X';
	rep(j, 0, 3) {
		int cnt = 0;
		rep(x, 0, n) {
			rep(y, 0, n) {
				d[x][y] = c[x][y];
				if ((x + y) % 3 == j && d[x][y] == 'X') ++cnt, d[x][y] = 'O';
			}
			d[x][n] = '\0';
		}
		if (cnt <= k / 3) {
			rep(x, 0, n) cout << d[x] << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}