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

const int N = 3e5 + 10;

vector<int> g[N];
int a[N], b[N];
int in[N], out[N];

bool anc(int u, int v) { return in[u] < in[v] && out[v] <= out[u]; }

int timer;
void init(int u) {
	in[u] = ++timer;
	for (int v : g[u]) init(v);
	out[u] = timer;
}

int ans;

set<array<int, 3>> s;

void add(int u) { s.insert({in[u], out[u], u}); }

void dfs(int u) {
	int rem = -1;
	if (auto it = s.lb({in[u], -1, -1}); it != begin(s) && out[u] <= (*(--it))[1]) {
		rem = (*it)[2];
		s.erase(it);
	}
	
	add(u);
	uax(ans, sz(s));
	for (auto v : g[u]) dfs(v);
	s.erase({in[u], out[u], u});
	if (rem != -1) add(rem);
}

int solve() {
	int n; cin >> n;
	
	rep(i, 1, n) cin >> a[i], --a[i];
	rep(i, 1, n) cin >> b[i], --b[i];
	
	rep(u, 0, n) g[u].clear();
	rep(i, 1, n) g[b[i]].push_back(i);
	
	init(0);

	rep(u, 0, n) g[u].clear();
	rep(i, 1, n) g[a[i]].push_back(i);
	
	assert(s.empty());
	ans = 0;
	dfs(0);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}