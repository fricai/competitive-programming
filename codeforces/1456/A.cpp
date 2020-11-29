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

const int N = 1 << 17;
const ll inf = 1e18;
ll f[2 * N];
char a[N];

ll solve() {
	int n, p, k, x, y; cin >> n >> p >> k >> a >> x >> y;
	fill(f + n, f + n + k, 0); --p;
	per(i, 0, n) f[i] = f[i + k] + (a[i] != '1' ? x : 0);

	ll ans = inf;
	for (int i = 0, z = 0; p + i < n; ++i, z += y) ckmin(ans, z + f[p + i]);
	cerr << '\n';

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}