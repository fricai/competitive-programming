#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;

vector<int> g[N];


/*
	Let in[u] be the max number of moves we can do in subtree of u

	Let out[u] be the max number of moves we can do outside the subtree of u

	Let cnti[u] be the max number of nodes we can remove from children of u

	Let cani[u] be true if we can turn u into a leaf while restricting ourselves to subtree of u

	Let cano[u] be true if we can turn p[u] into a leaf while restricting ourselves to T - (subtree of u)
*/

int in[N], out[N], cnti[N];
bool cani[N], cano[N];

int n, k;

void dfs1(int u, int p) {
	in[u] = cnti[u] = 0;
	trav(v, g[u]) {
		if (v == p) continue;
		dfs1(v, u);
		in[u] += in[v];
		cnti[u] += cani[v];
	}
	cani[u] = cnti[u] == sz(g[u]) - 1 && cnti[u] % k == 0;
	in[u] += cnti[u] / k;
}

void dfs2(int u, int p) {
	if (p != -1) {
		int cnto = cnti[p] - cani[u] + cano[p];
		out[u] = out[p] + in[p] - cnti[p] / k - in[u] + cnto / k;
		cano[u] = cnto == sz(g[p]) - 1 && cnto % k == 0;
	} else cano[u] = out[u] = 0;
	trav(v, g[u]) if (v != p) dfs2(v, u);
}

int solve() {
	cin >> n >> k;

	rep(u, 0, n) g[u].clear();

	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	
	dfs1(0, -1);
	dfs2(0, -1);
	
	int ans = 0;
	rep(u, 0, n) ckmax(ans, in[u] + out[u] - cnti[u] / k + (cnti[u] + cano[u]) / k);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}