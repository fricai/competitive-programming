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

const int N = 1 << 17;
ll w[N], ans[N], deg[N], ord[N];

void solve() {

	int n; cin >> n;
	
	rep(i, 0, n) cin >> w[i], deg[i] = 0, ord[i] = i;
	
	ll cur = 0;
	rep(e, 0, n - 1) {
		int u, v; cin >> u >> v;
		--u; --v;
		++deg[u]; ++deg[v];
		cur += w[u] + w[v];
	}
	sort(ord, ord + n, [&](int u, int v) {
		return w[u] < w[v];
	});

	int i = 0;
	per(j, 0, n - 1) {
		ans[j] = cur;
		while (i < n && deg[ord[i]] == 1) ++i;
		if (i < n) cur -= w[ord[i]], --deg[ord[i]];
	}
	rep(j, 0, n - 1) cout << ans[j] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}