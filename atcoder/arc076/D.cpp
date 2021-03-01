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
int x[N], y[N];
int ord[N];
vector<tuple<int, int, int>> edges;

int dist(int i, int j) { return min(abs(x[i] - x[j]), abs(y[i] - y[j])); }

int nxt[N];

int head(int u) { return nxt[u] != u ? nxt[u] = head(nxt[u]) : u; }
bool join(int u, int v) {
	u = head(u); v = head(v);
	if (u == v) return false;
	return nxt[u] = v, true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> x[i] >> y[i], ord[i] = nxt[i] = i;
	sort(ord, ord + n, [&](int i, int j) { return x[i] < x[j]; });
	rep(i, 1, n) edges.emplace_back(dist(ord[i], ord[i - 1]), ord[i], ord[i - 1]);
	sort(ord, ord + n, [&](int i, int j) { return y[i] < y[j]; });
	rep(i, 1, n) edges.emplace_back(dist(ord[i], ord[i - 1]), ord[i], ord[i - 1]);

	sort(all(edges));
	ll ans = 0;
	for (auto [cost, u, v] : edges)
		if (join(u, v)) ans += cost;
	cout << ans;
}