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

const int N = 1 << 7;
int a[N][N];
bool taken[N][N];

ll diff(const set<pair<int, int>> &s, ll target) {
	ll d = 0;
	for (auto [x, y] : s) d += abs(a[x][y] - target);
	return d;
}

ll solve() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j], taken[i][j] = false;
	vector<set<pair<int, int>>> eq;
	for (int i = 0; i < n && i <= n - i - 1; ++i)
		for (int j = 0; j < m && j <= m - j - 1; ++j)
			eq.push_back({{i, j}, {n - i - 1, j}, {n - i - 1, m - j - 1}, {i, m - j - 1}});
	ll ans = 0;
	for (auto s : eq) {
		vector<int> stuff;
		for (auto [x, y] : s) stuff.push_back(a[x][y]);
		sort(all(stuff));
		ll del;
		if (sz(stuff) & 1) del = diff(s, stuff[sz(stuff) / 2]);
		else del = min(diff(s, stuff[sz(stuff) / 2]), diff(s, stuff[sz(stuff) / 2 - 1]));
		ans += del;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}