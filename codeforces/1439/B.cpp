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

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
// struct chash {
//     const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
//     static unsigned long long hash_f(unsigned long long x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
//     int operator()(int x) const { return hash_f(x) ^ RANDOM; }
// };

const int N = 1 << 17;
vector<int> g[N], mn[N];
unordered_set<int> h[N];
int deg[N];
bool vis[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;

	rep(u, 0, n) g[u].clear(), h[u].clear();
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
		h[u].insert(v); h[v].insert(u);
	}

	if (1ll * k * (k - 1) / 2 > m) return void(cout << "-1\n");

	rep(u, 0, n) mn[u].clear();
	rep(u, 0, n) {
		vis[u] = 0;
		deg[u] = sz(g[u]);
		mn[deg[u]].push_back(u);
	}

	for (int x = 0; x < n; x = mn[x].empty() ? x + 1 : x) {
		if (mn[x].empty()) continue;

		int u = mn[x].back(); mn[x].pop_back();

		if (vis[u]) continue;

		vis[u] = true;

		g[u].erase(partition(all(g[u]), [&](int x) { return !vis[x]; }), end(g[u]));
		
		if (x == k - 1) {
			if ([&]() {
				for (int v : g[u])
					for (int x : g[u])
						if (x != v && !h[v].count(x))
							return false;
				return true;
			}()) {
				cout << "2\n" << u + 1;
				for (int v : g[u]) cout << ' ' << v + 1;
				cout << '\n';
				return;
			}
		}
		if (x < k) {
			for (int v : g[u]) {
				--deg[v];
				mn[deg[v]].push_back(v);
				ckmin(x, deg[v]);
			}
			continue;
		}

		vector<int> res = {u};
		rep(i, 0, n) for (int v : mn[i]) if (!vis[v]) res.push_back(v), vis[v] = true;
		cout << 1 << ' ' << sz(res) << '\n';
		for (int x : res) cout << x + 1 << ' ';
		cout << '\n';
		return;
	}	
	cout << "-1\n";
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) solve();
}