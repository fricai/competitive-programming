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

const int N = 1 << 9, M = (119 << 23) + 1;
vector<int> g[N];
ll res[N][N];
int d[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	rep(u, 0, n) rep(v, 0, n) d[u][v] = N;
	rep(u, 0, n)
		for (int v : g[u])
			d[u][v] = 1;
	rep(u, 0, n) d[u][u] = 0;

	rep(w, 0, n)
		rep(u, 0, n)
			rep(v, 0, n)
				ckmin(d[u][v], d[u][w] + d[w][v]);
	
	rep(u, 0, n) {
		rep(v, 0, n) {
			int c = 0;
			rep(w, 0, n) c += d[u][v] == d[u][w] + d[w][v];
			if (c != d[u][v] + 1) continue;
			res[u][v] = 1;
			rep(w, 0, n) {
				if (d[u][v] == d[u][w] + d[w][v]) continue;
				int c = 0;
				for (auto x : g[w])
					c += d[u][w] == d[u][x] + 1 && d[v][w] == d[v][x] + 1;
				res[u][v] = res[u][v] * c % M;
			}
		}
	}

	rep(u, 0, n) {
		rep(v, 0, n) cout << res[u][v] << ' ';
		cout << '\n';
	}
	
}