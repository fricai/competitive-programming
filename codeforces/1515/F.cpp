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

const int N = 3e5 + 10, M = N;
int a[M], b[M];
ll c[N];
vector<int> g[N];
bool vis[N];
ll x;
vector<int> one, two;

void dfs(int u) {
	vis[u] = 1;
	for (int e : g[u]) {
		int v = a[e] ^ b[e] ^ u;
		if (vis[v]) continue;
		dfs(v);
		
		if (c[v] >= x) {
			c[u] += c[v] - x;
			one.push_back(e);
		} else
			two.push_back(e);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m >> x;

	ll s = 0;
	rep(i, 0, n) cin >> c[i], s += c[i];
	rep(e, 0, m) {
		cin >> a[e] >> b[e]; --a[e], --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	if (s < (n - 1) * x)
		return cout << "NO\n", 0;

	dfs(0);
	
	assert(sz(one) + sz(two) == n - 1);
	reverse(all(two));

	cout << "YES\n";
	for (auto &v : {one, two})
		for (auto e : v)
			cout << e + 1 << '\n';
}