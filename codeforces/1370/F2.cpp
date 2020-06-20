#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i <= (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)

pair<int, int> ask(vector<int> &s) {
	cout << "? " << s.size();
	trav(x, s) cout << ' ' << x;
	cout << endl;

	s.clear();

	int v, d; cin >> v >> d;
	return {v, d};
}

const int N = 1 << 10;
vector<int> g[N];
int in[N], out[N], d[N], timer;
void dfs(int u) {
	in[u] = timer++;
	trav(v, g[u]) if (in[v] < 0) d[v] = d[u] + 1, dfs(v);
	out[u] = timer;
}

bool ancestor(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; }

void solve() {
	int n; cin >> n;

	timer = 0; rep(u, 1, n) g[u].clear(), in[u] = -1, d[u] = 0;

	rep(i, 2, n) {
		int u, v; cin >> u >> v;
		g[u].eb(v); g[v].eb(u);
	}

	vector<int> s; rep(u, 1, n) s.eb(u);
	int dist, l, r; tie(r, dist) = ask(s); l = r; dfs(r);
	
	while (dist) {
		rep(v, 1, n) {
			if (ancestor(v, l) || ancestor(v, r)) continue;
			if (ancestor(l, v) && d[v] - d[l] == (dist + 1) / 2 ||
				ancestor(r, v) && d[v] - d[r] == (dist + 1) / 2) s.eb(v);
		}

		int x;
		if (s.size() == 1) x = s.front();
		else x = ask(s).first;

		if (ancestor(l, x)) {
			dist -= d[x] - d[l];
			l = x;
		} else {
			dist -= d[x] - d[r];
			r = x;
		}
	}

	cout << "! " << l << ' ' << r << endl;
	string z; cin >> z;
}

signed main() {
	int t; cin >> t;
	while (t--) solve();
}