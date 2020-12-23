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

const int N = 1 << 18;
int a[N];
vector<int> g[N];
ll s[N], ss[N];

void init(int u, int p) {
	s[u] = a[u];
	for (int v : g[u]) {
		if (v == p) continue;
		init(v, u);
		s[u] += s[v];
		ss[u] += ss[v] + s[v];
	}
}

ll ans = 0;
void reroot(int u, int p) {
	ckmax(ans, ss[u]);
	for (int v : g[u]) {
		if (v == p) continue;
		ss[v] += (ss[u] - ss[v] - s[v]) + (s[u] - s[v]);
		s[v] = s[u];
		reroot(v, u);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	init(0, 0);
	reroot(0, 0);
	cout << ans;
}