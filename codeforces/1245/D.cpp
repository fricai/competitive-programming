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

const int N = 1 << 11;
const ll inf = 1e18;
ll c[N], k[N];
int x[N], y[N];
bool vis[N];
ll mnw[N];
int mnv[N];

ll f(int u, int v) {
	if (!u) return c[v];
	if (!v) return c[u];
	return (k[u] + k[v]) * (abs(x[u] - x[v]) + abs(y[u] - y[v]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) cin >> k[i];

	fill(mnw + 1, mnw + 1 + n, inf);

	ll res = 0;

	vector<pair<int, int>> tr;
	rep(i, 0, n + 1) {
		int u = -1;
		rep(j, 0, n + 1) if (!vis[j] && (u == -1 || mnw[j] < mnw[u])) u = j;
		vis[u] = true;
		res += mnw[u];
		tr.push_back({u, mnv[u]});
		rep(v, 0, n + 1) if (f(u, v) < mnw[v]) mnw[v] = f(u, v), mnv[v] = u;
	}

	vector<int> reactors; vector<pair<int, int>> connections;
	for (auto [x, y] : tr) {
		if (!x && !y) continue;
		if (!x) reactors.push_back(y);
		if (!y) reactors.push_back(x);
		if (x && y) connections.emplace_back(x, y);
	}

	cout << res << '\n';

	cout << sz(reactors) << '\n';
	for (auto v : reactors) cout << v << ' ';
	cout << '\n';
	
	cout << sz(connections) << '\n';
	for (auto [x, y] : connections) cout << x << ' ' << y << '\n';
	cout << '\n';
}