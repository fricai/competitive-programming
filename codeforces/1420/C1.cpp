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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 19;
const ll inf = 1e18;

int a[N];
ll f[N][2];

ll solve() {
	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	f[0][1] = -inf;
	f[0][0] = 0;
	rep(i, 0, n) {
		f[i + 1][1] = max(f[i][1], f[i][0] + a[i]);
		f[i + 1][0] = max(f[i][0], f[i][1] - a[i]);
	}
	return f[n][1];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}