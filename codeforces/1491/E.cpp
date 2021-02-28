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

const int B = 30;
int f[B];

const int N = 1 << 18;

vector<int> g[N];
int a[N], b[N];
bool dead[N];
int sz[N];

void get_sz(int u, int p) {
	sz[u] = 1;
	for (auto e : g[u]) {
		int v = a[e] ^ b[e] ^ u;
		if (v != p && !dead[e]) {
			get_sz(v, u);
			sz[u] += sz[v];
		}
	}
}

tuple<int, int, int> find_edge(int u, int p, int target) {
	int init_sz = sz[u];
		
	for (auto e : g[u]) {
		int v = a[e] ^ b[e] ^ u;

		if (v != p && !dead[e]) {
			if (sz[v] == target) return {e, u, v};
			if (sz[u] - sz[v] == target) return {e, v, u};
			
			int init_sz_v = sz[v];

			sz[v] = init_sz;
			sz[u] = init_sz - init_sz_v;

			auto res = find_edge(v, u, target);
			if (get<0>(res) != 0) return res;

			sz[u] = init_sz;
			sz[v] = init_sz_v;
		}
	}
	return {0, 0, 0};
}

bool recur(int u, int k) {

	if (k <= 3) return true;


	get_sz(u, 0);
	
	auto [edge, x, y] = find_edge(u, 0, f[k - 2]);

	if (edge == 0) return false;
	
	dead[edge] = true;

	return recur(x, k - 1) && recur(y, k - 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = f[1] = 1;
	rep(i, 2, B) f[i] = f[i - 1] + f[i - 2];

	int n; cin >> n;

	rep(e, 1, n) {
		cin >> a[e] >> b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}
	
	int k;
	for (k = 1; k < B; ++k) if (f[k] == n) break;
	if (k == B) return cout << "NO", 0;
	cout << (recur(1, k) ? "YES" : "NO");
}