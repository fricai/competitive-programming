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

	Let cnt[u] be the max number of nodes we can remove from children of u

	Let cand[u] be true if we can turn u into a leaf while restricting ourselves to subtree of u

	Let cand[u] be true if we can turn p[u] into a leaf while restricting ourselves to T - (subtree of u)
*/

int in[N], out[N], cnt[N];
bool cand[N], canu[N];

int n, k;

void dfs1(int u, int p) {
	in[u] = 0;

	cnt[u] = 0;
	trav(v, g[u]) {
		if (v == p) continue;
		dfs1(v, u);
		in[u] += in[v];
		cnt[u] += cand[v];
	}
	cand[u] = cnt[u] == sz(g[u]) - 1 && cnt[u] % k == 0;
	in[u] += cnt[u] / k;
}

void dfs2(int u, int p) {
	if (p != -1) {
		int sum = cnt[p] - cand[u] + canu[p];
		out[u] = out[p] + in[p] - cnt[p] / k - in[u] + sum / k;
		canu[u] = sum == sz(g[p]) - 1 && sum % k == 0;
	} else canu[u] = out[u] = 0;
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
	rep(u, 0, n) ckmax(ans, in[u] + out[u] - cnt[u] / k + (cnt[u] + canu[u]) / k);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}