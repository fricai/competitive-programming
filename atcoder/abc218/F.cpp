#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<int> a(m), b(m);
	rep(i, 0, m) cin >> a[i] >> b[i], --a[i], --b[i];
	vector<vector<int>> g(n);
	rep(e, 0, m) g[a[e]].push_back(e);

	vector<int> d(n, inf);
	queue<int> q;
	q.push(0);
	d[0] = 0;

	vector<int> p(n, -1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto e : g[u]) {
			int v = b[e];
			if (d[v] == inf) {
				d[v] = d[u] + 1;
				p[v] = e;
				q.push(v);
			}
		}
	}

	vector<int> ans(m, d[n - 1]);

	auto update = [&](int f) {
		vector<int> dist(n, inf);
		queue<int> q;
		q.push(0);
		dist[0] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto e : g[u]) {
				if (e == f)
					continue;
				int v = b[e];
				if (dist[v] == inf) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		ans[f] = dist[n - 1];
	};

	int root = n - 1;
	if (p[root] != -1) {
		while (root != 0) {
			update(p[root]);
			root = a[p[root]];
		}
	}

	for (auto x : ans)
		cout << (x < inf ? x : -1) << '\n';
}
