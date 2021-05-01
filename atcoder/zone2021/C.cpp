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

const int N = 3000 + 10, inf = 1e9 + 10, K = 5;
int a[N][K];
bool exists[1 << K];
int n;

bool f(int x) {
	rep(S, 0, 1 << K) {
		exists[S] = 0;
		rep(i, 0, n) {
			bool ok = 1;
			rep(j, 0, K) if (S >> j & 1) ok &= x <= a[i][j];
			exists[S] |= ok;
		}
	}
	rep(j, 0, n) {
		rep(i, 0, j) {
			int T = 0;
			rep(k, 0, K) if (x > max(a[i][k], a[j][k])) T |= 1 << k;
			if (exists[T]) return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 0, n) rep(j, 0, K) cin >> a[i][j];
	int l = 0, r = inf;
	while (r - l > 1) {
		// [l, r)
		int m = (l + r) / 2;
		(f(m) ? l : r) = m;
	}
	cout << l << '\n';
}