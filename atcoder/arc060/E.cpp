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

const int B = 17, N = 1 << B;
int x[N];
int p[B][N];
int d[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> x[i];
	int L; cin >> L;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && x[j] - x[i] <= L) ++j;
		p[0][i] = j - 1;
	}
	rep(j, 0, B - 1)
		rep(i, 0, n) p[j + 1][i] = p[j][p[j][i]];
	per(i, 0, n) d[i] = d[p[0][i]] + 1;
	
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v; --u; --v;
		if (u > v) swap(u, v);
		int t = u;
		
		per(j, 0, B) if (p[j][t] < v) t = p[j][t];
		t = p[0][t];
		cout << d[u] - d[t] << '\n';
	}
}