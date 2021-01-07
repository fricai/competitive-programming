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

const int B = 17, N = 1 << B, M = 1e9 + 7;
ll x[N];
vector<int> g[N];
ll ans;

void dfs(int u, map<ll, int> m) {
    ++m[x[u]];
    for (auto [val, cnt] : m) (ans += val * cnt) %= M;
	for (int v : g[u]) {
        g[v].erase(find(all(g[v]), u));
        map<ll, int> nxt;
        for (auto [val, cnt] : m) nxt[gcd(x[v], val)] += cnt;
        dfs(v, nxt);
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
    dfs(1, { });
	cout << ans;
}