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

const int N = 5e3 + 10, inf = 1e8 + 21;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	ll s = 0; rep(i, 0, n) s += i / 2;
	if (m > s) return cout << "-1\n", 0;
	if (m == s) {
		rep(i, 0, n) cout << i + 1 << ' ';
		cout << '\n';
		return 0;
	}

	int k = 0;
	for (s = 0; s <= m; ++k) s += k / 2;
	s -= (k - 1) / 2;
	--k;
	rep(i, 0, k) cout << i + 1 << ' ';
	cout << 2 * k + 1 - 2 * (m - s) << ' ';
	rep(i, k + 1, n) cout << inf + 2 * N * i << ' ';
}