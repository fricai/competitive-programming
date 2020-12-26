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

const int N = 1 << 10, K = 5;
int p[K][N], q[K][N], a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	rep(j, 0, k) rep(i, 0, n) cin >> p[j][i], q[j][p[j][i]] = i;

	int ans = 0;
	rep(i, 0, n) {
		int x = p[0][i];
		a[i] = 1;
		rep(j, 0, i) {
			int y = p[0][j];
			bool before = true;
			rep(l, 0, k) if (q[l][y] > q[l][x]) before = false;
			if (before) ckmax(a[i], a[j] + 1);
		}
		ckmax(ans, a[i]);
	}
	cout << ans << '\n';
}