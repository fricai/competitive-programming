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

const int N = 500000, B = 1 << 10;

ll a[N + 1], f[B][B];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while (q--) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			rep(n, 1, B) f[n][x % n] += y;
		} else {
			if (x < B) cout << f[x][y] << '\n';
			else {
				ll s = 0;
				for (int i = y; i <= N; i += x) s += a[i];
				cout << s << '\n';
			}
		}
	}
}