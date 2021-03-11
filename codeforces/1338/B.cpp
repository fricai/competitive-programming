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

const int N = 1 << 17;
vector<int> g[N];
vector<int> parities;
bool d[N];
int mx;
int cnt[2];

void dfs(int u) {
	if (g[u].empty()) ++cnt[d[u]];
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		d[v] = d[u] ^ 1;
		dfs(v);
	}
	int cnt = 0;
	for (int v : g[u]) cnt += g[v].empty();
	mx -= max(0, cnt - 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = -1;
	rep(u, 0, n) if (sz(g[u]) > 1) root = u;
	assert(0 <= root);
	mx = n - 1; cnt[0] = cnt[1] = 0;
	dfs(root);
	cout << (cnt[0] && cnt[1] ? 3 : 1) << ' ' << mx << '\n';
}