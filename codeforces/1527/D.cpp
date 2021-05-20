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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18, B = 18;
vector<int> g[N];
int p[N];
int sz[N];
int in[N], out[N];
int timer = 0;

void init(int u) {
	sz[u] = 1;
	in[u] = ++timer;
	for (auto v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		p[v] = u;
		init(v);
		sz[u] += sz[v];
	}
	out[u] = timer;
}

bool is_anc(int v, int u) {
	// v is anc of u if 
	return in[v] <= in[u] && out[u] <= out[v];
}

bool vis[N];
int deg[N];
ll f[N];

void solve() {
	int n; cin >> n;
	rep(u, 0, n) g[u].clear();
	rep(u, 0, n + 1) deg[u] = f[u] = vis[u] = 0;
	
	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	timer = 0;
	init(0);

	for (int v : g[0])
		f[0] += 1ll * sz[v] * (sz[v] - 1) / 2;

	int L = 0, R = 0;

	bool is_path = 1;

	vis[0] = 1;

	int child = 0;
	for (int x = 1; x < n; ++x) {
		// count pairs such that the mex is x + 1

		for (int v = x; !vis[v]; v = p[v]) {
			assert(v != 0);

			if (p[v] == L) L = x;
			else if (p[v] == R) {
				R = x;
				assert(L != x);
			}
			
			++deg[p[v]];

			if (p[v] != 0) {
				if (deg[p[v]] > 1) is_path = 0;
			} else {
				if (deg[0] > 2) is_path = 0;
				sz[0] -= sz[v];
				if (child == 0) child = v;
			}

			vis[v] = 1;
		}

		if (!is_path) break;

		assert(L != R);
		
		if (vis[x + 1]) continue;


		ll left = sz[L], right = sz[R];
		if (x + 1 != n) {
			if (is_anc(L, x + 1)) left -= sz[x + 1];
			else if (R != 0) {
				if (is_anc(R, x + 1)) right -= sz[x + 1];
			} else {
				if (!is_anc(child, x + 1))
					right -= sz[x + 1];
			}
		}
		
		f[x + 1] = left * right;
	}

	f[1] = n; f[1] *= n - 1; f[1] /= 2;
	rep(i, 0, n + 1) if (i != 1) f[1] -= f[i];

	rep(i, 0, n + 1) cout << f[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}