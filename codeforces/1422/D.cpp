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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;
int ord[N], x[N], y[N], n;
vector<pair<int, int>> g[N];

void join(int u, int v) {
	int d = min(abs(x[u] - x[v]), abs(y[u] - y[v]));
	g[u].emplace_back(d, v);
	g[v].emplace_back(d, u);
}

const ll inf = 1e18;
ll d[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int garbage; cin >> garbage >> n;

	cin >> x[n] >> y[n] >> x[n + 1] >> y[n + 1];
	rep(u, 0, n) cin >> x[u] >> y[u], ord[u] = u;

	sort(ord, ord + n, [&](int i, int j) { return x[i] < x[j]; });
	rep(i, 1, n) join(ord[i], ord[i - 1]);

	sort(ord, ord + n, [&](int i, int j) { return y[i] < y[j]; });
	rep(i, 1, n) join(ord[i], ord[i - 1]);

	rep(u, 0, n + 1) {
		int d = abs(x[u] - x[n + 1]) + abs(y[u] - y[n + 1]);
		g[n + 1].emplace_back(d, u);
		g[u].emplace_back(d, n + 1);
	}
	rep(u, 0, n) join(u, n);

	priority_queue<pair<ll, int>> q;
	rep(u, 0, n + 2) d[u] = inf;
	q.push({0, n}); d[n] = 0;

	while (!q.empty()) {
		auto [d_u, u] = q.top(); q.pop();
		if (-d_u != d[u]) continue;
		for (auto [w, v] : g[u]) if (ckmin(d[v], d[u] + w)) q.push({-d[v], v});
	}

	cout << d[n + 1];
}