#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;

const int N = 1 << 17;
vector<int> g[N];
int dp[N];

int f(int u) {
	auto &x = dp[u];
	if (x == -1) {
		x = 0;
		trav(v, g[u]) ckmax(x, 1 + f(v));
	}
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v);
	}
	rep(u, 0, n) dp[u] = -1;
	int ans = 0;
	rep(u, 0, n) ckmax(ans, f(u));
	cout << ans;
}