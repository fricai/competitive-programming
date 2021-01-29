#include <bits/stdc++.h>
#include <atcoder/modint>

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

const int M = 1e9 + 7;
using mint = atcoder::static_modint<M>;
const int N = 1 << 17;
mint x[N], y[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) {
		int a; cin >> a;
		x[i] = a;
	}
	rep(i, 0, m) {
		int a; cin >> a;
		y[i] = a;
	}
	mint X = 0, Y = 0;
	rep(i, 0, n) X += (n - 2 * i - 1) * x[i];
	rep(i, 0, m) Y += (m - 2 * i - 1) * y[i];
	cout << (X * Y).val();
}