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

const int N = 1 << 18, inf = 1e9;
ll a[N], b[N];

int solve() {
	int n, m; cin >> n >> m;

	rep(i, 0, n) cin >> a[i];

	rep(i, 0, n) cin >> b[i];
	
	vector<int> one, two;
	ll s = 0;
	rep(i, 0, n) {
		(b[i] == 1 ? one : two).push_back(a[i]);
		if (b[i] == 1) s += a[i];
	}
	sort(rall(one));
	sort(rall(two));
	
	int ans = inf;
	for (int x = sz(one), y = 0; x >= 0; --x) {
		while (y < sz(two) && s < m) s += two[y++];
		if (m <= s) ckmin(ans, x + 2 * y);
		if (x) s -= one[x - 1];	
	}

	return (ans < inf ? ans : -1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}