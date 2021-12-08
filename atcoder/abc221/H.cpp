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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector f(n + 1, vector<mint>(n + 1));
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			f[i][j] = f[i][j - i] + f[i - 1][j - 1];
			if (i > m) f[i][j] -= f[i - m - 1][j - i];
		}
	}

	for (int k = 1; k <= n; ++k)
		cout << f[k][n].val() << '\n';
}
