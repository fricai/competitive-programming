#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17, B = 21;
int n;
int a[N], b[N], w[N], c[N], leaves[N], wn[N], cn[N];
vector<int> g[N];

ll S, len;

void dfs(int u) {
	if (g[u].empty()) leaves[u] = 1;
	else leaves[u] = 0;
	for (int e : g[u]) {
		int v = u != a[e] ? a[e] : b[e];
		g[v].erase(find(all(g[v]), e));
		wn[v] = w[e];
		cn[v] = c[e];
		dfs(v);
		leaves[u] += leaves[v];
		len += 1ll * wn[v] * leaves[v];
	}
}

ll solve() {
	int n; cin >> n >> S;
	rep(u, 0, n) g[u].clear();
	len = 0;
	rep(e, 1, n) {
		cin >> a[e] >> b[e] >> w[e] >> c[e];
		--a[e]; --b[e];
		g[a[e]].eb(e);
		g[b[e]].eb(e);
	}
	dfs(0);
	vector<ll> one, two;
	auto gain = [&](int u) { return 1ll * (wn[u] + 1) / 2 * leaves[u]; };
	rep(u, 0, n) {
		if (cn[u] == 1) while (wn[u]) one.eb(gain(u)), wn[u] /= 2;
		else  while (wn[u]) two.eb(gain(u)), wn[u] /= 2;
	}
	sort(all(one)); sort(all(two));
	one.eb(0); two.eb(0);
	reverse(all(one)); reverse(all(two));
	int ans = 1e9;
	rep(i, 1, sz(two)) two[i] += two[i - 1];
	rep(i, 1, sz(one)) one[i] += one[i - 1];
	rep(i, 0, sz(one)) {
		int j = lb(all(two), len - one[i] - S) - begin(two);
		if (j != sz(two)) ckmin(ans, 2 * j + i);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}