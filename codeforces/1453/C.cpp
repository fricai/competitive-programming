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

const int N = 1 << 11, A = 10;
int a[N][N], b[N][N], ans[N];
int n;

int solve(int d, int a[][N]) {
	int mx = 0;
	rep(i, 0, n) {
		int fst = -1, lst = -1;
		rep(j, 0, n) if (a[i][j] == d) { fst = j; break; }
		rep(j, 0, n) if (a[i][j] == d) lst = j;
		if (fst != -1) ckmax(mx, max(i, n - i - 1) * (lst - fst));
	}

	int fst = -1, lst = -1;
	per(i, 0, n) rep(j, 0, n) if (a[i][j] == d) fst = i;
	if (fst == -1) return mx;
	rep(i, fst + 1, n) rep(j, 0, n) if (a[i][j] == d) ckmax(mx, (i - fst) * max(j, n - j - 1));
	rep(i, 0, n) rep(j, 0, n) if (a[i][j] == d) lst = i;
	assert(lst != -1);
	rep(i, 0, lst) rep(j, 0, n) if (a[i][j] == d) ckmax(mx, (lst - i) * max(j, n - j - 1));
	return mx;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
	cin >> n;
	rep(i, 0, n)
		rep(j, 0, n)  {
			char c; cin >> c;
			b[j][i] = a[i][j] = c - '0';
		}
		rep(i, 0, A) cout << max(solve(i, a), solve(i, b)) << ' ';
		cout << '\n';
	}
}