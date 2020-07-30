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

const int N = 1 << 18;
ll a[N], b[N], dp[N], number[N];
bool up[N];
vector<int> g[N], root, ord;
int timer = 0;

void dfs(int u) {
	dp[u] = a[u];
	trav(v, g[u]) {
		dfs(v);
		if (up[v]) dp[u] += dp[v];
	}
	if (dp[u] > 0) up[u] = true;
}

ll ans = 0;
void construct(int u) {
	trav(v, g[u]) if (up[v]) construct(v);
	ans += dp[u]; ord.eb(u + 1);
	trav(v, g[u]) if (!up[v]) construct(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i], --b[i];
	rep(u, 0, n) if (b[u] >= 0) g[b[u]].eb(u);
	rep(u, 0, n) if (b[u] < 0) dfs(u);
	rep(u, 0, n) if (b[u] < 0) construct(u);
	cout << ans << '\n';
	trav(x, ord) cout << x << ' ';
}