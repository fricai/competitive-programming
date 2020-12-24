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

const int N = 1 << 17, M = 1 << 17, W = 1 << 17, NC = 6e6;

int t[NC], L[NC], R[NC], tot;

int dp_end[N], dp_start[N];

void update(int v, int p, int x, int l = 0, int r = W) {
	if (r - l == 1) return void(ckmax(t[v], x));
	int m = (l + r) / 2;
	if (p < m) {
		if (!L[v]) L[v] = tot++;
		update(L[v], p, x, l, m);
	} else {
		if (!R[v]) R[v] = tot++;
		update(R[v], p, x, m, r);
	}
	t[v] = max(t[L[v]], t[R[v]]);	
}

int query(int v, int lo, int hi, int l = 0, int r = W) {
	if (!v || hi <= l || r <= lo) return 0;
	if (lo <= l && r <= hi) return t[v];
	int m = (l + r) / 2;
	return max(query(L[v], lo, hi, l, m), query(R[v], lo, hi, m, r));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	tot = n + 1;

	int ans = 0;
	rep(e, 0, m) {
		int a, b, w; cin >> a >> b >> w;
		int cur = 1 + query(a, 0, w);
		update(b, w, cur);
		ckmax(ans, cur);
	}
	cout << ans << '\n';
}