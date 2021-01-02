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

const int N = 1 << 17, M = 1 << 17;
vector<int> g[N];
bool taken[M];
int a[M], b[M];

int dfs(int u) {
	g[u].erase(partition(all(g[u]), [&](int e) { return !taken[e]; }), end(g[u]));
	
	for (int e : g[u]) taken[e] = true;
	
	vector<int> not_taken;
	for (int e : g[u]) {
		int v = a[e] ^ b[e] ^ u;
		int res = dfs(v);
		if (res) cout << u << ' ' << v << ' ' << res << '\n';
		else not_taken.push_back(v);
	}

	while (sz(not_taken) > 1) {
		int a = not_taken.back(); not_taken.pop_back();
		int b = not_taken.back(); not_taken.pop_back();
		cout << a << ' ' << u << ' ' << b << '\n';
	}

	return not_taken.empty() ? 0 : not_taken[0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	if (m & 1) return cout << "No solution", 0;
	rep(e, 0, m) {
		cin >> a[e] >> b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}
	dfs(1);
}