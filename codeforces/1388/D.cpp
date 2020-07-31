#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 18;
ll a[N];
vector<int> g[N];

ll ans = 0;
void dfs(int u) {
	trav(v, g[u]) {
		dfs(v);
		if (a[v] > 0) a[u] += a[v];
	}
}

void construct(int u) {
	trav(v, g[u]) if (a[v] > 0) construct(v);
	cout << u + 1 << ' ';
	trav(v, g[u]) if (a[v] <= 0) construct(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	vector<int> roots;
	rep(u, 0, n) {
		int p; cin >> p;
		if (p-- > 0) g[p].eb(u);
		else roots.eb(u);
	}

	trav(v, roots) dfs(v);
	cout << accumulate(a, a + n, 0ll) << '\n';
	trav(v, roots) construct(v);
}