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

const int N = 1 << 17, M = 1e9 + 7;
int dp[N];
vector<int> g[N];


void add(int &a, int b) { a += b; if (M <= a) a -= M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(e, 1, n) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b); g[b].push_back(a);
	}

	int leaves = 0;
	rep(u, 0, n) if (sz(g[u]) == 1) ++leaves;

	int tot = 1;
	rep(u, 0, n - leaves) add(tot, tot);

	int ans = 0;
	rep(u, 0, n) {
		add(ans, tot);
		if (sz(g[u]) == 1) add(ans, tot);
	}
	cout << ans;
}