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

const int N = 1 << 18;
vector<int> g[N];
int deg[N];
int p[N];
int a[N];
bool dead[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		cin >> p[i];
		g[--p[i]].push_back(i);
	}

	fill_n(a, N, -1);

	auto assign = [&](int u, int x = 0) {
		set<int> z;
		for (int v : g[u]) {
			z.insert(a[v]);
		}
		while (z.count(x)) ++x;
		return x;
	};

	stack<int> s;
	rep(i, 0, n) {
		deg[i] = sz(g[i]);
		if (deg[i] == 0) s.push(i);
	}
	
	while (!s.empty()) {
		int u = s.top(); s.pop();
		dead[u] = 1;
		if (--deg[p[u]] == 0) s.push(p[u]);
		a[u] = assign(u);
	}
	
	int t = -1;
	rep(u, 0, n) if (!dead[u]) t = u;
	assert(t != -1);

	auto test = [&](int x) {
		a[t] = x;
		for (int v = p[t]; v != t; v = p[v])
			a[v] = assign(v);
		rep(u, 0, n) if (a[u] != assign(u)) return 0;
		return 1;
	};

	int opt = assign(t);
	if (test(opt) || test(assign(t, opt + 1))) return cout << "POSSIBLE\n", 0;
	cout << "IMPOSSIBLE\n";
}