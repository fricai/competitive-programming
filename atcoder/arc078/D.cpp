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

int n;
vector<int> g[N];
vector<int> path;
bool find_path(int u, int p) {
	if (u == 1) {
		path.push_back(u);
		return 1;
	}
	
	for (int v : g[u]) {
		if (v != p && find_path(v, u)) {
			path.push_back(u);
			return 1;
		}
	}
	return 0;
}

int sz[N];

void find_sz(int u, int p) {
	sz[u] = 1;
	for (int v : g[u]) {
		if (v == p) continue;
		find_sz(v, u);
		sz[u] += sz[v];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	find_path(n, 0);
	
	auto del = [&](int u, int v) {
		g[u].erase(find(all(g[u]), v));
		g[v].erase(find(all(g[v]), u));
	};
	rep(i, 1, sz(path)) del(path[i - 1], path[i]);
	
	for (auto root : path) find_sz(root, 0);

	int one = 0, two = 0;
	for (int l = 0, r = sz(path), turn = 0; l < r; turn ^= 1) {
		if (turn) two += sz[path[--r]];
		else one += sz[path[l++]];
	}

	assert(one + two == n);

	cout << (one > two ? "Fennec" : "Snuke") << '\n';
}