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

const int N = 1 << 10;
int a[N][N];
int c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	
	
	int cur = 0;
	rep(i, 0, n) cur ^= a[i][i];

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 3) cout << cur;
		if (t == 2 || t == 1) {
			int i; cin >> i; --i;
			cur ^= 1;
		}
	}
}