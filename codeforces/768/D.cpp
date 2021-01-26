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

const int K = 1 << 10, N = 1 << 14;
ld f[N][K];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, q; cin >> k >> q;
	f[0][0] = 1;
	rep(i, 1, N)
		for (int j = 0; j <= k; ++j) {
			f[i][j] += j * f[i - 1][j] / k;
			f[i][j + 1] += (k - j) * f[i - 1][j] / k;
		}
	
	while (q--) {
		int p; cin >> p;
		rep(i, 1, N)
			if (p <= f[i][k] * 2000) {
				cout << i << '\n';
				break;
			}
	}
}