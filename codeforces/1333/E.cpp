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

const int N = 1 << 9;
int g[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	if (n <= 2) return cout << -1, 0;
	int k = n;
	int cur = 0;
	for (int k = n, parity = 0; k > 3; --k, parity ^= 1) {
		if (parity) {
			for (int i = 1; i <= k; ++i) g[k][i] = ++cur;
			for (int i = k - 1; i > 0; --i) g[i][k] = ++cur;
		} else {
			for (int i = 1; i <= k; ++i) g[i][k] = ++cur;
			for (int i = k - 1; i > 0; --i) g[k][i] = ++cur;
		}
	}
	g[1][1] = 9; g[1][2] = 5; g[1][3] = 6;
	g[2][1] = 7; g[2][2] = 2; g[2][3] = 8;
	g[3][1] = 1; g[3][2] = 3; g[3][3] = 4;
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j)
			g[i][j] += cur;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}