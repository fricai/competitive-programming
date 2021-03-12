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

const int N = 3e5 + 10, B = 19;
int nxt[B][N], mn[B][N], a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	rep(b, 0, B) {
		nxt[b][n] = n;
		mn[b][n] = n;
	}

	per(u, 0, n) {
		rep(b, 0, B) mn[b][u] = n;
		rep(b, 0, B) {
			int &v = nxt[b][u];
			v = nxt[b][u + 1];


			if (a[u] >> b & 1) {
				ckmin(mn[b][u], v);
				rep(c, 0, B) ckmin(mn[c][u], mn[c][v]);
				v = u;
			}
		}
	}
	
	while (q--) {
		int u, v; cin >> u >> v; --u; --v;

		bool ok = false;
		rep(b, 0, B) ok |= (a[v] >> b & 1) && mn[b][u] <= v;
		cout << (ok ? "Shi" : "Fou") << '\n';
	}
}