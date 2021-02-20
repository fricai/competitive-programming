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

const ll inf = 1e18;
const int N = 1 << 17, M = N;
vector<tuple<int, int, int>> g[N];
ll d[N];

ll nxt(ll t, ll k) { return (t + k - 1) / k * k; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x, y; cin >> n >> m >> x >> y; --x; --y;
	rep(e, 0, m) {
		int a, b, t, k; cin >> a >> b >> t >> k; --a; --b;
		g[a].emplace_back(b, t, k);
		g[b].emplace_back(a, t, k);
	}

	fill_n(d, n, inf);
    d[x] = 0;

    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> q;
	auto add = [&q](int x) { q.push({d[x], x}); };
	add(x);

    while (!q.empty()) {
		auto [d_u, u] = q.top(); q.pop();
        if (d_u != d[u]) continue;
		for (auto [v, t, k] : g[u]) if (ckmin(d[v], nxt(d[u], k) + t)) add(v);
	}

	cout << (d[y] < inf ? d[y] : -1);
}