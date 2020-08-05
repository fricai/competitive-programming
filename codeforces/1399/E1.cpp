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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17, B = 21;
int n;
int a[N], b[N], w[N], p[N], leaves[N], wn[N];
vector<int> g[N];

ll len = 0, S;

void dfs(int u) {
	if (g[u].empty()) leaves[u] = 1;
	else leaves[u] = 0;
	for (int e : g[u]) {
		int v = u != a[e] ? a[e] : b[e];
		g[v].erase(find(all(g[v]), e));
		wn[v] = w[e];
		dfs(v);
		leaves[u] += leaves[v];
		len += 1ll * leaves[v] * wn[v];
	}
}

ll solve() {
	int n; cin >> n >> S;
	rep(u, 0, n) g[u].clear();
	len = 0;
	rep(e, 1, n) {
		cin >> a[e] >> b[e] >> w[e];
		--a[e]; --b[e];
		g[a[e]].eb(e);
		g[b[e]].eb(e);
	}
	dfs(0);
	int cnt = 0;
	priority_queue<pair<ll, int>> pq;
	rep(u, 1, n) pq.push({1ll * (wn[u] + 1) / 2 * leaves[u], u});
	while (len > S) {
		ll x; int u; tie(x, u) = pq.top(); pq.pop();
		len -= x; ++cnt; wn[u] /= 2;
		pq.push({1ll * (wn[u] + 1) / 2 * leaves[u], u});
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}