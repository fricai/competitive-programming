#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using vi = vector<int>;

constexpr int N = 1 << 17;
int M;
int f[N], h[N];
vi g[N];

void down(int u, int p) {
	f[u] = 1;
	if (p != u) g[u].erase(find(all(g[u]), p));
	trav(v, g[u]) {
		down(v, u);
		f[u] = 1ll * f[u] * (1 + f[v]) % M;
	}
}

void up(int u, int p) {
	int c = sz(g[u]);
	vi s(c + 1, 1); int x = 1;
	per(i, 0, c) s[i] = 1ll * s[i + 1] * (1 + f[g[u][i]]) % M;
	rep(i, 0, c) {
		int v = g[u][i];
		h[v] = 1ll * x * s[i + 1] % M * (1 + h[u]) % M;
		x = 1ll * x * (1 + f[v]) % M;
		up(v, u);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n >> M;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	down(0, 0);
	up(0, 0);
	rep(u, 0, n) cout << 1ll * f[u] * (1 + h[u]) % M << '\n';
}