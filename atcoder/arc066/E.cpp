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

const int N = 1 << 17;
ll mx[2][N], mn[2][N];
int a[N];
char op[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	cin >> a[0];
	rep(i, 1, n) cin >> op[i - 1] >> a[i];
	// rep(i, 0, n) cerr << a[i] << ' ';

	// 0 for +, 1 for -
	mn[0][n - 1] = mx[0][n - 1] = +a[n - 1];
	mn[1][n - 1] = mx[1][n - 1] = -a[n - 1];

	per(i, 0, n - 1) {
		if (op[i] == '-') {
			mn[0][i] = a[i] + mn[1][i + 1];
			mx[0][i] = a[i] + mx[1][i + 1];

			mn[1][i] = -a[i] + min(-mx[1][i + 1], mn[1][i + 1]);
			mx[1][i] = -a[i] + max(-mn[1][i + 1], mx[1][i + 1]);
		} else {
			mn[0][i] = a[i] + mn[0][i + 1];
			mx[0][i] = a[i] + mx[0][i + 1];
			mn[1][i] = -a[i] + mn[1][i + 1];
			mx[1][i] = -a[i] + max(mx[0][i + 1], mx[1][i + 1]);
		}
	}

	cout << mx[0][0];
}