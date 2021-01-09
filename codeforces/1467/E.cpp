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

const int B = 18, N = 1 << 18;
set<int> s[N];
vector<int> g[N];
int a[N], in[N], out[N], timer;

bool valid[N], up_valid[N];

void init(int u, int p) {
	in[u] = ++timer;
	s[u] = {a[u]};

	valid[u] = true;

	for (int v : g[u]) {
		if (v == p) continue;

		init(v, u);

		up_valid[v] = valid[v] && !s[v].count(a[u]);
		valid[u] &= up_valid[v];

		if (sz(s[v]) > sz(s[u])) swap(s[u], s[v]);
		for (auto x : s[v]) s[u].insert(x);
	}

	out[u] = timer;
}

int mx[N], mn[N];

int cnt = 0;
void reroot(int u, int p) {
	cnt += valid[u];

	vector<bool> r(sz(g[u]) + 1, 1);
	per(i, 0, sz(g[u])) r[i] = up_valid[g[u][i]] && r[i + 1];
	
	bool l = 1;
	bool init_up_valid_u = up_valid[u];
	bool init_valid_u = valid[u];
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		if (v != p) {
			bool init_valid_v = valid[v];
			
			valid[u] = l && r[i + 1];
			up_valid[u] = valid[u] && in[v] <= mn[a[v]] && mx[a[v]] <= out[v];
			valid[v] = valid[v] && up_valid[u];

			reroot(v, u);

			valid[u] = init_valid_u;
			valid[v] = init_valid_v;
			up_valid[u] = init_up_valid_u;
		}

		l &= up_valid[v];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> cmp(n);
	for (int i = 1; i <= n; ++i) cin >> a[i], cmp[i - 1] = a[i];
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
	for (int i = 1; i <= n; ++i) a[i] = lower_bound(all(cmp), a[i]) - begin(cmp);

	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	init(1, 0);

	for (int i = 1; i <= n; ++i) {
		if (mn[a[i]] == 0) mn[a[i]] = in[i], mx[a[i]] = out[i];
		else ckmin(mn[a[i]], in[i]), ckmax(mx[a[i]], out[i]);
	}

	reroot(1, 0);

	cout << cnt;
}