#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// why
using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(e, x) for (auto &e : x)

#define eb(x...) emplace_back(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
vector<int> g[N];
int mx[N];
bool del[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;

		rep(i, 0, m) {
			int x, y; cin >> x >> y; --x; --y;
			g[y].eb(x);
		}

		rep(u, 0, n) {
			trav(v, g[u])
				if (mx[v] < 2) ckmax(mx[u], mx[v] + 1);
			if (mx[u] == 2) del[u] = true;
		}

		int k = 0;
		rep(u, 0, n) k += del[u];
		// assert(7 * k <= 4 * n);		
		cout << k << '\n';
		rep(u, 0, n) if (del[u]) cout << u + 1 << ' ';
		cout << '\n';

		rep(u, 0, n) g[u].clear();
		rep(u, 0, n) mx[u] = del[u] = 0;
	}
}