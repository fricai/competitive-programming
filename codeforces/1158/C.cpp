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

const int N = 1 << 19;
int nxt[N], p[N];
int k;

bool dfs(int l, int r) {
	for (int u = l; u < r; u = nxt[u]) {
		if (nxt[u] > r || !dfs(u + 1, nxt[u])) return 0;
		p[u] = ++k;
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	rep(i, 0, n) {
		cin >> nxt[i], --nxt[i];
		if (nxt[i] < 0) nxt[i] = i + 1;
	}
	k = 0;
	if (!dfs(0, n)) return void(cout << "-1\n");

	rep(i, 0, n) cout << p[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}