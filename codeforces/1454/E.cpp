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
bool dead[N];
ll cnt[N];

ll solve() {
	int n; cin >> n;

	rep(u, 0, n) g[u].clear(), deg[u] = 0, dead[u] = 0, cnt[u] = 1;
	rep(e, 0, n) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		++deg[u];
		++deg[v];
	}

	stack<int> st;
	rep(u, 0, n) if (deg[u] == 1) st.push(u);
	while (!st.empty()) {
		int u = st.top(); st.pop();
		dead[u] = 1;
		for (auto v : g[u]) {
			if (dead[v]) continue;
			cnt[v] += cnt[u];
			if (--deg[v] == 1) st.push(v);
		}
	}

	ll ans = 0;
	rep(u, 0, n) {
		if (dead[u]) continue;
		ans += cnt[u] * (cnt[u] - 1) / 2 + cnt[u] * (n - cnt[u]);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}