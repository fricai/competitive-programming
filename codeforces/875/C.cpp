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
vector<int> s[N];
vector<int> g[N];
bool capital[N], vis[N];

vector<int> res;
void dfs(int u) {
	vis[u] = 1;
	res.push_back(u);
	for (int v : g[u]) if (!vis[v]) dfs(v);
}

bool check(vector<int> a, vector<int> b) {
	for (auto &x : a) if (vis[x]) x -= N;
	for (auto &y : b) if (vis[y]) y -= N;
	int r = 0, k = min(sz(a), sz(b));
	while (r < k && a[r] == b[r]) ++r;
	if (r == k) return sz(a) <= sz(b);
	return a[r] < b[r];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) {
		int k; cin >> k;
		s[i].resize(k);
		for (auto &x : s[i]) cin >> x;
	}
	rep(i, 1, n) {
		int r = 0, k = min(sz(s[i - 1]), sz(s[i]));
		while (r < k && s[i - 1][r] == s[i][r]) ++r;
		if (r == k) continue;
		int u = s[i - 1][r], v = s[i][r];
		if (u > v) {
			// capitalize s[i - 1][r]
			capital[u] = 1;
		} else {
			g[v].push_back(u);
		}
	}

	for (int c = 1; c <= m; ++c) if (!vis[c] && capital[c]) dfs(c);
	rep(i, 1, n) if (!check(s[i - 1], s[i])) return cout << "No\n", 0;
	cout << "Yes\n";
	cout << sz(res) << '\n';
	for (auto x : res) cout << x << ' ';
}